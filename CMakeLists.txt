cmake_minimum_required(VERSION 3.24)
project(2_sort_search)

set(CMAKE_CXX_STANDARD 23)

add_executable(2_sort_search main.cpp array.cpp array.h quadratic_sort.cpp quadratic_sort.h linear_sort.cpp linear_sort.h nlogn_sort.cpp nlogn_sort.h search.cpp search.h)
