cmake_minimum_required(VERSION 3.15)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp file.cpp file.h get_started.cpp get_started.h board.h board.cpp player.h player_setup.cpp player_setup.h player.cpp play.cpp play.h)
