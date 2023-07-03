cmake_minimum_required(VERSION 3.23)
project(workshop8_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(workshop8_2
        main2.c
        w8p2.c
        w8p2.h)
