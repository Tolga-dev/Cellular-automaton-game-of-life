cmake_minimum_required(VERSION 3.23)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(GameOfLife ${SDL2_INCLUDE_DIRS})

add_executable(GameOfLife main_sdl_basic_glider.cpp)

target_link_libraries(GameOfLife ${SDL2_LIBRARIES})