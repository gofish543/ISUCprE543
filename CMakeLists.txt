cmake_minimum_required(VERSION 3.14)
project(ISUCprE543)

add_executable(ISUCprE543 main.cpp AccessPoint.cpp AccessPoint.h)

target_link_libraries(ISUCprE543 iw)
target_link_libraries(ISUCprE543 m)