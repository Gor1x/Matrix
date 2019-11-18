cmake_minimum_required(VERSION 3.15)
project(Matrix)

set(flags "-Werror -Wall -Wextra -pedantic")
SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${flags}")
set(CMAKE_CXX_STANDARD 14)

add_executable(Matrix main.cpp matrix.cpp matrix.h)