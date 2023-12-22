cmake_minimum_required(VERSION 3.22.1)
project(game_core)

set(CMAKE_CXX_STANDART 17)

include_directories(headers)

add_executable(project_game main.cpp 
                            map.cpp
                            Tank.cpp
                            Soldier.cpp
                            player.cpp
                            objects.cpp)
