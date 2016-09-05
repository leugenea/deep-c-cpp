cmake_minimum_required(VERSION 3.6)
project(deep_c_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(01_triangle 01-triangle.cpp)

add_executable(02_growing 02-growing.cpp)
