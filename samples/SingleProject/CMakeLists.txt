cmake_minimum_required(VERSION 3.15)

find_package(Catch2 3 REQUIRED)

project(AwesomeProject VERSION 1.0)

# Set C++ Version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# source folder files to be compiled
set(SRC_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/src")

# tests folder files to be run
set(TEST_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/test")

# source files to be compiled
file(GLOB_RECURSE SRC_FILES 
    "${SRC_FOLDER}/*.cpp" 
    "${SRC_FOLDER}/*.c"
    "${SRC_FOLDER}/**/*.cpp" 
    "${SRC_FOLDER}/**/*.c")
    
# tests files to be run
file(GLOB_RECURSE TEST_FILES 
"${TEST_FOLDER}/*.cpp" 
"${TEST_FOLDER}/*.c"
"${TEST_FOLDER}/**/*.cpp" 
"${TEST_FOLDER}/**/*.c")

# header files to be compiled
set(INCLUDE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include")

# add executable target
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} main.cpp)

# set default configuration to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(MSVC) # setup for Windows
    # enable parallel compilation
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

    # specify supported configurations
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

    # specify supported Platform
    set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "" FORCE)

    # avoid auto generation of additional projects ALL_BUILD and ZERO_CHECK
    set(CMAKE_SUPPRESS_REGENERATION TRUE)
    set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY TRUE)
    
    # options for the project
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:/DEBUG>
        $<$<CONFIG:Release>:/O2>)
else() # setup for Linux
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wunused -Wextra -Wunused -Wuninitialized")
    
    # specify supported configurations
    set(CMAKE_BUILD_TYPE Debug Release)
    
    # specify supported Platform
    set(CMAKE_SYSTEM_PROCESSOR "x86_64")

    # options for the project
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:-O0>
        $<$<CONFIG:Debug>:-g>
        $<$<CONFIG:Release>:-O2>)

endif()

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_FILES})
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_SOURCE_DIR}/bin/${PROJECT_NAME})

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

####################### UNIT TESTS SECTION ######################
# Check Catch2
find_package(Catch2 REQUIRED)

if(Catch2_FOUND)
    # These tests can use the Catch2-provided main
    add_executable(${PROJECT_NAME}Tests ${TEST_FILES} ${SRC_FILES} ${HEADER_FILES})
    # Include directories
    target_include_directories(${PROJECT_NAME}Tests PUBLIC ${INCLUDE_FILES} "src")
    # Include libraries
    target_link_libraries(${PROJECT_NAME}Tests PRIVATE Catch2::Catch2WithMain)
    # Set output directory
    set_target_properties(${PROJECT_NAME}Tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

    # adding custom tartget to execute tests 
    add_custom_target(
        run-test	
        COMMAND make ${PROJECT_NAME}Tests
        COMMAND ../bin/${PROJECT_NAME}Tests
        COMMENT "Running Unit Tests"
    )
    
    # Set Doxygen cleaning files
    set_property(
        DIRECTORY
        APPEND PROPERTY
        ADDITIONAL_MAKE_CLEAN_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/bin/${PROJECT_NAME}Tests
    )
else()
    message(STATUS "Catch2 not found, run unit tests disabled")
endif()
################################################################# 

######################## CPPCHECK SECTION ####################### 
# Check Cppcheck
find_program(CPPCHECK cppcheck)

if(CPPCHECK)
    # Definining cppcheck options
    set(CMAKE_CXX_CPPCHECK 
        ${CPPCHECK}
        --std=c++20 # handle C++20 standard
        --enable=warning,style,performance,portability
        --force
        --error-exitcode=1
    )

    # Set output file with the results
    set(CPPCHECK_OUTPUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/bin/cppcheck.log)

    # adding custom target to execute CppCheck analysis on source files
    add_custom_target(
        static-check
        COMMAND ${CMAKE_CXX_CPPCHECK}
        ${SRC_FOLDER} 2> ${CPPCHECK_OUTPUT_FILE}
        COMMENT "Running Cppcheck static analysis"
    )
    
    # Set Doxygen cleaning files
    set_property(
        DIRECTORY
        APPEND PROPERTY
        ADDITIONAL_MAKE_CLEAN_FILES
        ${CPPCHECK_OUTPUT_FILE}
    )
else()
    message(STATUS "Cppcheck not found, static analysis disabled")
endif()
################################################################# 

######################## DOXYGEN SECTION ######################## 
# check Doxygen
find_package(Doxygen)

if(DOXYGEN_FOUND)
    # set doxygen file path
    set(DOXYFILE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

    # Set output directory for documentation
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin/docs)

    # adding custom tartget to generate doxygen documentation 
    add_custom_target(
        run-doc
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DOXYGEN_OUTPUT_DIR}
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_PATH}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
    )
    
    # Set Doxygen cleaning files
    set_property(
        DIRECTORY
        APPEND PROPERTY
        ADDITIONAL_MAKE_CLEAN_FILES
        ${DOXYGEN_OUTPUT_DIR}
    )
else()
    message(STATUS "Doxygen not found, unable to generate documentation")
endif()
################################################################# 
