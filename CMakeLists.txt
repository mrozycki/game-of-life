cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

set(CMAKE_CXX_RELEASE_FLAGS -O3)
set(CMAKE_CXX_DEBUG_FLAGS -Og -g)

add_subdirectory(src)