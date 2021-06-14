cmake_minimum_required(VERSION 3.12)

file(GLOB CALC_SRC CONFIGURE_DEPENDS "../include/*.hpp" "../src/*.cpp")
add_executable(Calculator calculator.cpp ${CALC_SRC})
