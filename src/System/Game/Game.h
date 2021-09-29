//
// Created by lucas on 9/11/21.
//

#ifndef ADVETUREGAME_GAME_H
#define ADVETUREGAME_GAME_H
#include "../Tools/common.h"
#include "../Engine/Engine.h"
#include "TextureAtlas.h"
#include "Objects/Character_Types/Player.h"


class Engine;

class Game : public Engine {
	SDL_Event* event;
	Scene* currentScene;
	bool shiftModifier{false};
	vd2d mousePos {5,5};
	///mouse offset to center things to the pointer
	int mo{-132};
	/// index offset to offset from the the mouse offset
	int io {64};


public:
Player p1;

 double bsx{92};
 double bsy{600};



	Game();
	~Game();
	void execute();
	void handleEvents();
	void loop();

	void keyDown(const SDL_KeyboardEvent& e);
	void keyUp(const  SDL_KeyboardEvent& e);
	void mouseWheelUp(SDL_MouseWheelEvent& e);
	void mouseDown(const SDL_MouseButtonEvent& e);
	void mouseUp(const SDL_MouseButtonEvent& e);
	void mouseMotion(const SDL_MouseMotionEvent& e);


const vd2d VERTICAL_PATH {5,0};


};


#endif //ADVETUREGAME_GAME_H
