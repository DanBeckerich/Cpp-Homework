cmake_minimum_required(VERSION 3.14)
project(C5E5)

set(CMAKE_CXX_STANDARD 14)

add_executable(C5E5 main.cpp include/infix.hpp src/infix.cpp include/util.hpp src/util.cpp)