cmake_minimum_required(VERSION 3.10)
project(TD1_Partie1)

set(CMAKE_CXX_STANDARD 11)

add_library(tugabudoire STATIC tugabudoire.cpp tugabudoire.h)

add_executable(main main.cpp)
target_link_libraries(main tugabudoire)