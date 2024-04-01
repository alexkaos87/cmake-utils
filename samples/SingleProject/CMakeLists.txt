cmake_minimum_required(VERSION 3.15)

#set(PROJECT_NAME "AwesomeProject")

project(AwesomeProject VERSION 1.0)

# Set C++ Version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# source files to be compiled
file(GLOB_RECURSE SRC_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp" 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.c")

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
