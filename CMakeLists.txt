cmake_minimum_required(VERSION 3.27)
project(fig12_03 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(fig12_03
        ins_arr.c
        stackExample.c)
