cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++17)
set(CXX_FLAGS, "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PointsDistance)

add_executable(PointsDistance "src/main.cpp" "src/Point.cpp")