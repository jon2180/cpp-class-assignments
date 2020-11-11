cmake_minimum_required(VERSION 3.10)
project(gomoku_game)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

aux_source_directory(src dirSrc)

add_executable(gomoku ${dirSrc})
