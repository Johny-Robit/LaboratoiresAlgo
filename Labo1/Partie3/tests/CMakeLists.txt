# Crée une bibliothèque statique
add_library(test_tugabudoire STATIC test_tugabudoire.cpp)

# Indique où sont les fichiers sources (headers) nécessaire pour compiler la bibliothèque de test
target_include_directories(test_tugabudoire PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Force l'utilisation du standard C++14
target_compile_features(test_tugabudoire PUBLIC cxx_std_14)