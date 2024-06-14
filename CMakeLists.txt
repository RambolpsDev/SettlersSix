cmake_minimum_required(VERSION 3.28)
project(SettlersSix)
set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR SDL2/cmake)
set(SDL2_image_DIR SDL2_image/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(SettlersSix src/main.cpp src/Texture.cpp
        src/GameBoard.cpp
        src/GameBoard.h
        src/GameState.cpp
        src/GameState.h
        src/Player.cpp
        src/Player.h
        src/Card.cpp
        src/Card.h
        src/ResourceCard.cpp
        src/ResourceCard.h
        src/DevelopmentCard.cpp
        src/DevelopmentCard.h
        src/LongestRoadCard.cpp
        src/LongestRoadCard.h
        src/LargestArmyCard.cpp
        src/LargestArmyCard.h
        src/Skyscraper.cpp
        src/Skyscraper.h
        src/House.cpp
        src/House.h
        src/Road.cpp
        src/Road.h
        src/Thief.cpp
        src/Thief.h)
target_link_libraries(SettlersSix SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)