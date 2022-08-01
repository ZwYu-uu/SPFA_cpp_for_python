cmake_minimum_required(VERSION 3.5.1)
project(SPFA)

set(CMAKE_BUILD_TYPE "Release")
add_subdirectory(pybind11)
pybind11_add_module(SPFA SPFA.cpp)