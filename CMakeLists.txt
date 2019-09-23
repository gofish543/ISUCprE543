cmake_minimum_required(VERSION 3.14)
project(ISUCprE543)

set(CMAKE_CXX_STANDARD_LIBRARIES "-ltins -lmnl")

set(CMAKE_CXX_STANDARD 11)

add_executable(ISUCprE543 wifi_scan.c main.cpp AccessPoint.cpp AccessPoint.h)