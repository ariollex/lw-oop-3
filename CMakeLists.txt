cmake_minimum_required(VERSION 3.10)

project(2025_LW_OOP_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Install Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
  TLS_VERIFY false
)
FetchContent_MakeAvailable(googletest)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${INCLUDE_DIR})

# Build
add_library(Point_lib src/Point.cpp)
add_library(Figure_lib src/Figure.cpp)
add_library(Rhomb_lib src/rhomb.cpp)
add_library(Pentagon_lib src/pentagon.cpp)
add_library(Hexagon_lib src/hexagon.cpp)
add_executable(Figures_exe main.cpp)
target_link_libraries(Figures_exe PRIVATE Figure_lib Point_lib Rhomb_lib Pentagon_lib Hexagon_lib)

# Build Tests
enable_testing()
add_executable(Figures_tests test/tests.cpp)
target_link_libraries(Figures_tests Figure_lib Point_lib Rhomb_lib Pentagon_lib Hexagon_lib gtest_main)
