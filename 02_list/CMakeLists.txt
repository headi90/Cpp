cmake_minimum_required(VERSION 2.8.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wconversion -Werror")

project(list)

add_executable(${PROJECT_NAME} main3.cpp)
