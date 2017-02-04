cmake_minimum_required(VERSION 3.6)
project(GameEngine)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_VERBOSE_MAKEFILE 1)
set(COMMON_COMPILE_FLAGS "-Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers")

set(SOURCE_FILES src/main.cpp)
add_executable(GameEngine ${SOURCE_FILES})