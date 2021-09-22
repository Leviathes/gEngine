//
// Created by lucas on 9/11/21.
//

#ifndef ADVETUREGAME_GAME_H
#define ADVETUREGAME_GAME_H
#include "../../System/hpp/common.h"
#include "../../System/hpp/engine.h"
#include "../../System/hpp/textureAtlas.h"
#include "player.h"


class engine;

class game : public engine {
	SDL_Event* event;
	scene* currentScene;

public:
player p1;



	game();
	~game();
	void execute();
	void handleEvents();
	void loop();

	void keyDown(const SDL_KeyboardEvent& e);
	void keyUp(const  SDL_KeyboardEvent& e);

	void mouseDown(const SDL_MouseButtonEvent& e);
	void mouseUp(const SDL_MouseButtonEvent& e);





};


#endif //ADVETUREGAME_GAME_H
