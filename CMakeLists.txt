cmake_minimum_required(VERSION 3.12)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2 -Wall")

include_directories(include src)
add_subdirectory(calculator)
add_subdirectory(test)
add_subdirectory(src)
