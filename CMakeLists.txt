cmake_minimum_required(VERSION 3.13)
project(ISUCprE543)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)

include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})

add_executable(ISUCprE543 main.cpp AccessPoint.cpp AccessPoint.h helpers.cpp helpers.h packets.cpp packets.h)

add_definitions(${GTK2_CFLAGS_OTHER})
target_link_libraries(ISUCprE543 ${GTK2_LIBRARIES})
target_link_libraries(ISUCprE543 nm)
target_link_libraries(ISUCprE543 ncurses)
target_link_libraries(ISUCprE543 pcap)
