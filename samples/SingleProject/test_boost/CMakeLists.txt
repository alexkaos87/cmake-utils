cmake_minimum_required(VERSION 3.20)

set(BOOST_TESTS_PROJECT ${PROJECT_NAME}BoostTests)

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

# Exclude files in the turtle folder
set(EXCLUDED_FOLDER "${TEST_FOLDER}/turtle")

# Filter the files
foreach(FILE ${TEST_FILES})
    if(${FILE} MATCHES ${EXCLUDED_FOLDER})
        list(REMOVE_ITEM TEST_FILES ${FILE})
    endif()
endforeach()

# header files to be compiled
set(INCLUDE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../include" "${TEST_FOLDER}/turtle/include")

####################### UNIT TESTS SECTION ######################
# Check Boost 
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

if(Boost_FOUND)
    # These tests can use the Boost-provided main
    add_executable(${BOOST_TESTS_PROJECT} ${TEST_FILES} ${SRC_FILES} ${HEADER_FILES})
    # Include directories
    target_include_directories(${BOOST_TESTS_PROJECT} PUBLIC ${INCLUDE_FILES})
    # Include libraries
    target_link_libraries(${BOOST_TESTS_PROJECT} PRIVATE ${Boost_LIBRARIES})
    # Set output directory
    set_target_properties(${BOOST_TESTS_PROJECT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

    # adding custom tartget to execute tests 
    add_custom_target(
        test-boost
        COMMAND make ${BOOST_TESTS_PROJECT}
        COMMAND ../../bin/${BOOST_TESTS_PROJECT}
        COMMENT "Running Boost Unit Tests"
    )
    
    # Set boost tests cleaning files
    set_property(
        DIRECTORY
        APPEND PROPERTY
        ADDITIONAL_MAKE_CLEAN_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/../bin/${BOOST_TESTS_PROJECT}
    )
else()
    message(STATUS "Boost not found, run unit tests disabled")
endif()
################################################################# 
