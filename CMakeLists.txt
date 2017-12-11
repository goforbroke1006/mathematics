cmake_minimum_required(VERSION 3.7)
project(mathematics)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(mathematics ${SOURCE_FILES})


set(TESTS_SOURCE_FILES tests/catch.hpp tests/parser-test.cpp)
add_executable(tests_mathematics ${TESTS_SOURCE_FILES})