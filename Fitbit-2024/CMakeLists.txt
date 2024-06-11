cmake_minimum_required(VERSION 3.28)
project(Fitbit_2024 C)

set(CMAKE_C_STANDARD 11)

add_executable(Fitbit_2024 main.c
        equations.c
        equations.h)
