cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "AwesomeMultiProject")

project(${PROJECT_NAME})

# Set C++ Version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    # enable parallel compilation
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wunused -Wextra")
endif()

# source files to be compiled
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp")

# header files to be compiled
set(INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add executable target
add_executable(${PROJECT_NAME} ${SRC_FILES} main.cpp)

add_subdirectory(AwesomeLib1)
add_subdirectory(AwesomeLib2)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_FILES} "AwesomeLib1" "AwesomeLib2")
target_link_libraries(${PROJECT_NAME} AwesomeLib1 AwesomeLib2)
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_SOURCE_DIR}/bin/${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")



