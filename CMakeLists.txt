cmake_minimum_required(VERSION 3.18)
project(AdventureGame)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2TTF REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

add_executable(AdventureGame
        Game/cpp/main.cpp
        System/hpp/common.h
        System/hpp/toolBox.h System/cpp/toolBox.cpp
        System/hpp/engine.h System/cpp/engine.cpp
        Game/hpp/game.h Game/cpp/game.cpp

        Game/hpp/entity.h Game/cpp/entity.cpp

        System/hpp/vd2d.h System/cpp/vd2d.cpp

        System/hpp/renderer.h System/cpp/renderer.cpp

        Game/hpp/sprite.h Game/cpp/sprite.cpp

        System/hpp/textureAtlas.h System/cpp/textureAtlas.cpp

        Game/hpp/scene.h Game/cpp/scene.cpp

        System/hpp/texture.h System/cpp/texture.cpp

        FileReader/fileReader.cpp FileReader/hpp/fileReader.h System/cpp/camera.cpp System/hpp/camera.h Game/cpp/player.cpp Game/hpp/player.h System/cpp/GUI.cpp System/hpp/GUI.h)

target_link_libraries(AdventureGame ${SDL2_LIBRARIES}  ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY})
