# compiler le projet avec un build
# pour lancer les tests faire : ctest ou ctest --verbose
# donc:
# cmake
# make
# ctest --verbose

cmake_minimum_required(VERSION 3.14)
project(file_exec)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
#)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)

FetchContent_MakeAvailable(googletest)

add_executable(file_exec main.cpp)

enable_testing()

add_subdirectory(tests)
