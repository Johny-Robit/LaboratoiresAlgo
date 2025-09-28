cmake_minimum_required(VERSION 3.10)

# Nom du projet et langage
project(TugabudoireProject LANGUAGES CXX)

# Dossier des headers
# Indique où se trouvent les fichiers .h et .hpp
include_directories(${PROJECT_SOURCE_DIR})


# Exécutable principal
# Compiler l'exécutable avec les fichiers sources : inclure les .cpp nécessaires
# Pas besoin d'inclure les .h/.hpp ici
add_executable(partie3_tugabudoire
        main.cpp
        Tugabudoire.cpp
)

# Active le système de test de CMake
enable_testing()

# Exécutable pour les tests
add_executable(test_tugabudoire_partie3
        tests/test_tugabudoire.cpp
        Tugabudoire.cpp
)

# Lier l’exécutable de test avec GoogleTest
target_link_libraries(test_tugabudoire_partie3 PRIVATE gtest gtest_main)

# Pour COMMAND, utiliser le même nom que l'exécutable pour les tests
add_test(NAME TugabudoireTests COMMAND test_tugabudoire_partie3)

# fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)

# Récupère et rend disponible les cibles gtest/gmock
FetchContent_MakeAvailable(googletest)

# active à nouveau les tests au cas où
enable_testing()

# Ajoute le sous-répertoire tests/ s’il a son propre CMakeLists.txt
add_subdirectory(tests)
