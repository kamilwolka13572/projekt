cmake_minimum_required(VERSION 3.7.2 FATAL_ERROR)

project(pp2p C)

set(CMAKE_C_COMPILER "gcc")

set(CMAKE_C_STANDARD 11)

include(GNUInstallDirs)

link_libraries(m)

add_executable(pp2p main.c search.c save_to_file.c read_from_file.c printing.c editing.c deleting.c adding.c)
