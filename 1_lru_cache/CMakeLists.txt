# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.24.1)

# Name the project
project(lru_cache)

set(SRC_FILES "lru_cache.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})