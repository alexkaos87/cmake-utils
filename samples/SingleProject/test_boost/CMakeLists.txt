cmake_minimum_required(VERSION 3.15)

# source folder files to be compiled
set(SRC_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/../src")

# tests folder files to be run
set(TEST_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}")

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
set(INCLUDE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../include")

####################### UNIT TESTS SECTION ######################
# Check Boost 
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

if(Boost_FOUND)
    # These tests can use the Boost-provided main
    add_executable(${PROJECT_NAME}BoostTests ${TEST_FILES} ${SRC_FILES} ${HEADER_FILES})
    # Include directories
    target_include_directories(${PROJECT_NAME}BoostTests PUBLIC ${INCLUDE_FILES} "../src")
    # Include libraries
    target_link_libraries(${PROJECT_NAME}BoostTests PRIVATE ${Boost_LIBRARIES})
    # Set output directory
    set_target_properties(${PROJECT_NAME}BoostTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

    # adding custom tartget to execute tests 
    add_custom_target(
        run-test-boost
        COMMAND make ${PROJECT_NAME}BoostTests
        COMMAND ../../bin/${PROJECT_NAME}BoostTests
        COMMENT "Running Boost Unit Tests"
    )
    
    # Set boost tests cleaning files
    set_property(
        DIRECTORY
        APPEND PROPERTY
        ADDITIONAL_MAKE_CLEAN_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/../bin/${PROJECT_NAME}BoostTests
    )
else()
    message(STATUS "Boost not found, run unit tests disabled")
endif()
################################################################# 
