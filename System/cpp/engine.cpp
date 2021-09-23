//
// Created by lucas on 9/11/21.
//

#include "../hpp/engine.h"

engine::engine() {}
engine::~engine() {

	dbm("engine destructor");

	clean<SDL_Renderer>(Renderer.get());
	clean<SDL_Window>(Window);
}

bool engine::init() {
	toolBox::dbm("engine init()...");

	int rendererFlags{SDL_RENDERER_ACCELERATED  };
	int windowFlags{SDL_WINDOW_OPENGL};


	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		err("SDL Failed to Initialize");

		return false;
	}

	if((IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG )) < 0) {
		err("SDL failed to load image processing");
		return false;
	}

	if(TTF_Init() == -1) {
		err("SDL failed to initialize ttf");
		return false;
	}

	if(!(Window = SDL_CreateWindow("R.P.G", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags))) {
		err("SDL failed to Create Window");
		clean(Window);
		return false;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "fastest");


	if(!(Renderer.set(SDL_CreateRenderer(Window, -1, rendererFlags)))) {
		err("SDL failed to create Renderer");
		clean(Renderer.get());
		clean(Window);
		return false;
	}
	SDL_GL_SetSwapInterval(1);
	return true;
}


void engine::frameLimiter(const Uint32& frameTime_ms) {
	if (frameTime_ms < frameLimit) {
		SDL_Delay(frameLimit - frameTime_ms);
	}
}

bool engine::quit() {

	return _quit;
}

void engine::quit(bool state) {
	_quit = state;
}
