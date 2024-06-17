cmake_minimum_required(VERSION 3.28)
project(data_structure_code C)

set(CMAKE_C_STANDARD 11)

add_executable(data_structure_code hello-algo/linked_list.c
        hello-algo/array.c)
