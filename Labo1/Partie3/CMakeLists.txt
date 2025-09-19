cmake_minimum_required(VERSION 3.10)
project(TugabudoireProject LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR}/tests)
include(FetchContent)

# Download and make GoogleTest available
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Main executable
add_executable(partie3_tugabudoire
        main.cpp
        Tugabudoire.cpp
        Tugabudoire.h
)

enable_testing()

# Test executable
add_executable(test_tugabudoire_partie3
        test_tugabudoire.cpp
        Tugabudoire.cpp
        Tugabudoire.h
)

# Link to GoogleTest targets
target_link_libraries(test_tugabudoire_partie3 PRIVATE gtest gtest_main)

add_test(NAME TugabudoireTests COMMAND test_tugabudoire)
