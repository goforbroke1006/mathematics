cmake_minimum_required(VERSION 3.7)
project(mathematics)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Parser.h Node.h)
add_executable(mathematics ${SOURCE_FILES})

set(TESTS_SOURCE_FILES tests/catch.hpp tests/unit.cpp)
add_executable(mathematics_unit_tests ${TESTS_SOURCE_FILES})