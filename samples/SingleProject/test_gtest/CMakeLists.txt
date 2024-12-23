cmake_minimum_required(VERSION 3.20)

set(GOOGLE_TESTS_PROJECT ${PROJECT_NAME}GtestTests)

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
# Check gtest
find_package(GTest REQUIRED)

if(GTest_FOUND)
    # These tests can use the gtest-provided main
    add_executable(${GOOGLE_TESTS_PROJECT} ${TEST_FILES} ${SRC_FILES} ${HEADER_FILES})
    # Include directories
    target_include_directories(${GOOGLE_TESTS_PROJECT} PUBLIC ${INCLUDE_FILES})
    # Include libraries
    target_link_libraries(${GOOGLE_TESTS_PROJECT} PRIVATE gtest gmock GTest::gtest_main GTest::gmock_main)
    # Set output directory
    set_target_properties(${GOOGLE_TESTS_PROJECT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

    # adding custom tartget to execute tests 
    add_custom_target(
        test-gtest
        COMMAND make ${GOOGLE_TESTS_PROJECT}
        COMMAND ../../bin/${GOOGLE_TESTS_PROJECT}
        COMMENT "Running gtest Unit Tests"
    )
    
    # Set gtest tests cleaning files
    set_property(
        DIRECTORY
        APPEND PROPERTY
        ADDITIONAL_MAKE_CLEAN_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/../bin/${GOOGLE_TESTS_PROJECT}
    )
else()
    message(STATUS "gtest not found, run unit tests disabled")
endif()
################################################################# 
