cmake_minimum_required(VERSION 3.25)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GameOfLife
        ansi_escapes.cc
        ansi_escapes.h
        cell.cc
        cell.h
        grid.cc
        grid.h
        life.h
        main.cc)
