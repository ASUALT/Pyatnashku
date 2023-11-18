cmake_minimum_required(VERSION 3.26)
project(Projects)

set(CMAKE_CXX_STANDARD 17)
set(optimizations "-Ofast -mavx2 -funroll-loops")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${optimizations}")

add_executable(Projects main.cpp
        Fishka.cpp
        Fishka.h
        Field.cpp
        Field.h
)
