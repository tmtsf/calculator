cmake_minimum_required(VERSION 3.12)

file(GLOB CALC_SRC CONFIGURE_DEPENDS "../include/*.hpp" "*.cpp")
add_executable(Calculator ${CALC_SRC})
