cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(untitled
        Ability.h
        AbilityException.cpp
        AbilityException.h
        AbilityManager.cpp
        AbilityManager.h
        AttackOutOfField.cpp
        AttackOutOfField.h
        Bombing.cpp
        Bombing.h
        DoubleDamage.cpp
        DoubleDamage.h
        Exception.cpp
        Exception.h
        Game.cpp
        Game.h
        GameField.cpp
        GameField.h
        main.cpp
        PlaceShipException.cpp
        PlaceShipException.h
        Scanner.cpp
        Scanner.h
        Ship.cpp
        Ship.h
        ShipManager.cpp
        ShipManager.h)
