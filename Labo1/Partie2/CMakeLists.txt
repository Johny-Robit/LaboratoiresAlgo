cmake_minimum_required(VERSION 3.10)
project(TD1_Partie2)

set(CMAKE_CXX_STANDARD 11)

# Add the subdirectory containing the library
add_subdirectory(Tugabudoire)

# Build the executable from your main source file(s)
add_executable(main main.cpp)

# Link the static library to the executable
target_link_libraries(main PRIVATE tugabudoire)