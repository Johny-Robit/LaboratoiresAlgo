# Create the library from the source files
add_library(tugabudoire STATIC Tugabudoire.cpp)

# Specify include directories for the library
# indique que les fichiers d'en-tête .h sont dans le même répertoire que CMakeLists.txt
target_include_directories(tugabudoire PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# indique que la bibliothèque utilise C++14
target_compile_features(tugabudoire PUBLIC cxx_std_14)
