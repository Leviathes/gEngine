//
// Created by lucas on 9/15/21.
//

#ifndef ADVENTUREGAME_CAMERA_H
#define ADVENTUREGAME_CAMERA_H
#include "vd2d.h"
#include "SDL.h"
#include "../../Game/hpp/player.h"

class camera {
public:
	vd2d pos;
	SDL_Rect* cameraView;
	double zoomFactor {1};

	camera();

	void move(const player& p);
};


#endif //ADVENTUREGAME_CAMERA_H
