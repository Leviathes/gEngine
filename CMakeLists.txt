cmake_minimum_required(VERSION 3.18)
project(AdventureGame)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2TTF REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

add_executable(AdventureGame
        cpp/main.cpp
        hpp/common.h
        hpp/toolBox.h cpp/toolBox.cpp
        hpp/engine.h cpp/engine.cpp
        hpp/game.h cpp/game.cpp

        hpp/entity.h cpp/entity.cpp

        hpp/vd2d.h cpp/vd2d.cpp

        hpp/renderer.h cpp/renderer.cpp

        hpp/sprite.h cpp/sprite.cpp

        hpp/textureAtlas.h cpp/textureAtlas.cpp

        hpp/scene.h cpp/scene.cpp

        hpp/texture.h cpp/texture.cpp

        cpp/fileReader.cpp hpp/fileReader.h cpp/camera.cpp hpp/camera.h cpp/player.cpp hpp/player.h cpp/GUI.cpp hpp/GUI.h)

target_link_libraries(AdventureGame ${SDL2_LIBRARIES}  ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY})
