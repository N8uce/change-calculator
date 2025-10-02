cmake_minimum_required(VERSION 3.14)
project(ChangeCalculatorTest)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(change change.cpp)
target_include_directories(change PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_change tests/test_change.cpp)
target_link_libraries(test_change PRIVATE change gtest gtest_main)

enable_testing()
add_test(NAME test_change COMMAND test_change)
