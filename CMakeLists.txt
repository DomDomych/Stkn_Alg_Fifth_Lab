cmake_minimum_required(VERSION 3.10)

project(FifthLab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FifthLab
    example/main.cpp
    tree/tree.cpp
)

target_include_directories(FifthLab PRIVATE
    tree
    map
)