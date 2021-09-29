cmake_minimum_required(VERSION 3.18)
project(AdventureGame)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2TTF REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

add_executable(AdventureGame
        src/main.cpp
        src/System/Tools/common.h

        src/System/Engine/Engine.h src/System/Engine/Engine.cpp
        src/System/Game/Game.h src/System/Game/Game.cpp
        src/System/Tools/ToolBox.h src/System/Tools/ToolBox.cpp
        src/System/Game/Objects/Character_Types/Entity.h src/System/Game/Objects/Character_Types/Entity.cpp

        src/System/Tools/vd2d.h src/System/Tools/vd2d.cpp

        src/System/Engine/Renderer.h src/System/Engine/Renderer.cpp

        src/System/Game/Sprite.h src/System/Game/Sprite.cpp

        src/System/Game/TextureAtlas.h src/System/Game/TextureAtlas.cpp

        src/System/Game/Scene.h src/System/Game/Scene.cpp
        src/System/Game/Objects/Character_Types/Worker.h
        src/System/Game/Objects/Character_Types/Worker.cpp
        src/System/Game/Texture.h src/System/Game/Texture.cpp

        src/System/Tools/FileReader/fileReader.cpp src/System/Tools/FileReader/fileReader.h src/System/Engine/Camera.cpp src/System/Engine/Camera.h src/System/Game/Objects/Character_Types/Player.cpp src/System/Game/Objects/Character_Types/Player.h src/System/Game/GUI/GUI.cpp src/System/Game/GUI/GUI.h src/System/Game/Objects/Character_Types/Fighter.cpp src/System/Game/Objects/Character_Types/Fighter.h src/System/Game/Objects/Character_Types/Healer.cpp src/System/Game/Objects/Character_Types/Healer.h src/System/Game/Objects/Character_Types/King.cpp src/System/Game/Objects/Character_Types/King.h src/System/Game/Objects/Structure_Types/Tree.cpp src/System/Game/Objects/Structure_Types/Tree.h src/System/Game/Objects/Structure_Types/Rock.cpp src/System/Game/Objects/Structure_Types/Rock.h src/System/Game/Objects/Structure_Types/Building.cpp src/System/Game/Objects/Structure_Types/Building.h)

target_link_libraries(AdventureGame ${SDL2_LIBRARIES}  ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY} )
