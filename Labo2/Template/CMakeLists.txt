cmake_minimum_required(VERSION 3.10)
project(Labo2_Template)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# Programme principal
add_executable(Labo2_Template
        src/main.cpp
        src/Adresse.cpp
        src/Personne.cpp
        src/ContratException.cpp
)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Exécutable de tests
add_executable(test_Labo2_Template
        tests/test_personne.cpp
        tests/test_adresse.cpp
        src/Adresse.cpp
        src/Personne.cpp
        src/ContratException.cpp
)

target_link_libraries(test_Labo2_Template PRIVATE gtest gtest_main)

add_test(NAME Labo2TemplateTests COMMAND test_Labo2_Template)

