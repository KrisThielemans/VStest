cmake_minimum_required(VERSION 3.17)

PROJECT(VCTest)

add_library(mylib Derived.cpp)
add_executable(test test.cpp)
target_link_libraries(test mylib)
