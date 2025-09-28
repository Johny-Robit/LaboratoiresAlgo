cmake_minimum_required(VERSION 3.14)
project(ListeSimpleCirculaire LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)
FetchContent_MakeAvailable(googletest)

add_library(
        ListeSimpleCirculaireLib
        Liste.hpp
        Liste.h
        ContratException.cpp
        ContratException.h
)

add_executable(ListeTesteur ListeTesteur.cpp)

target_link_libraries(ListeTesteur
        ListeSimpleCirculaireLib
        gtest_main
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(ListeTesteur)

