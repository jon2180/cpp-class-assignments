cmake_minimum_required(VERSION 3.15)
project(gomoku_console)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(gomoku_console
        src/GameController.cpp
        src/GameController.h
        src/GameData.cpp
        src/GameData.h
        src/GameView.cpp
        src/GameView.h
        src/Gomoku.cpp
        src/pch.cpp
        src/pch.h)
