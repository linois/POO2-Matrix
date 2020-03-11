cmake_minimum_required(VERSION 3.15)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Matrix
        main.cpp
        Matrix.cpp
        Matrix.h
        operators.h)
