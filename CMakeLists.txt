cmake_minimum_required(VERSION 3.27)
project(l1_2024)

set(CMAKE_CXX_STANDARD 17)

add_executable(l1_2024 main.cpp
        Hero.h
        PositiveHero.cpp
        PositiveHero.h
        Villain.cpp
        Villain.h
        Monster.cpp
        Monster.h
        Keeper.cpp
        Keeper.h
)
