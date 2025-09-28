cmake_minimum_required(VERSION 3.14)

project(ListeSimpleCirculaire LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES
        ${PROJECT_SOURCE_DIR}/ListeTesteur.cpp
        ${PROJECT_SOURCE_DIR}/ContratException.cpp
)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)
FetchContent_MakeAvailable(googletest)

enable_testing() # rends les cibles gtest et gtest_main disponibles

add_executable(listeCirculaire_tests ${TEST_SOURCES})

target_link_libraries(
        listeCirculaire_tests
        gtest_main
        gtest
        pthread
)

include(CTest)
include(GoogleTest)
gtest_discover_tests(listeCirculaire_tests)

