# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.24.1)

# Name the project
project(lru_cache)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC_FILES
    test.cpp
)

enable_testing()

add_executable(test_lru_cache ${SRC_FILES})
target_link_libraries(
    test_lru_cache
    GTest::gtest_main
    GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(test_lru_cache)