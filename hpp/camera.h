//
// Created by lucas on 9/15/21.
//

#ifndef ADVENTUREGAME_CAMERA_H
#define ADVENTUREGAME_CAMERA_H
#include "vd2d.h"
#include "SDL.h"
#include "player.h"

class camera {
public:
	vd2d pos;
	SDL_Rect* cameraView;

	camera();

	void move(const player& p);
};


#endif //ADVENTUREGAME_CAMERA_H
