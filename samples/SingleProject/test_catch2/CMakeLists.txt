cmake_minimum_required(VERSION 3.20)

set(CATCH2_TESTS_PROJECT ${PROJECT_NAME}Catch2Tests)

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
# Check Catch2
find_package(Catch2 REQUIRED)

if(Catch2_FOUND)
    find_package(GTest REQUIRED)
    
    # These tests can use the Catch2-provided main
    add_executable(${CATCH2_TESTS_PROJECT} ${TEST_FILES} ${SRC_FILES} ${HEADER_FILES})
    # Include directories
    target_include_directories(${CATCH2_TESTS_PROJECT} PUBLIC ${INCLUDE_FILES})
    # Include libraries
    target_link_libraries(${CATCH2_TESTS_PROJECT} PRIVATE Catch2::Catch2WithMain gmock GTest::gmock_main)
    # Set output directory
    set_target_properties(${CATCH2_TESTS_PROJECT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

    # adding custom tartget to execute tests 
    add_custom_target(
        test-catch2	
        COMMAND make ${CATCH2_TESTS_PROJECT}
        COMMAND ../../bin/${CATCH2_TESTS_PROJECT}
        COMMENT "Running catch2 Unit Tests"
    )
    
    # Set catch2 tests cleaning files
    set_property(
        DIRECTORY
        APPEND PROPERTY
        ADDITIONAL_MAKE_CLEAN_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/../bin/${CATCH2_TESTS_PROJECT}
    )
else()
    message(STATUS "Catch2 not found, run unit tests disabled")
endif()
################################################################# 
