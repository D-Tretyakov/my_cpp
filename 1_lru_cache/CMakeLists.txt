# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.24.1)

# Name the project
project(lru_cache)

set(SRC_FILES
    main.cpp
)

add_executable(test_lru_cache ${SRC_FILES})