//
// Created by lucas on 9/11/21.
//

#ifndef ADVETUREGAME_ENGINE_H
#define ADVETUREGAME_ENGINE_H

#include "common.h"
#include "renderer.h"


class engine {


	bool _quit;
	SDL_Window* Window;
	Uint32 frameLimit{16};


public:

	renderer Renderer;
	engine();
	~engine();

	bool init();

	void frameLimiter(const Uint32& frameTime_ms);

	bool quit();
	void quit(bool state);



};


#endif //ADVETUREGAME_ENGINE_H
