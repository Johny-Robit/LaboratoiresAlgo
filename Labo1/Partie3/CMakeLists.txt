cmake_minimum_required(VERSION 3.10)
project(TugabudoireProject LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR}/tests)

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

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)

FetchContent_MakeAvailable(googletest)
enable_testing()
add_subdirectory(tests)
