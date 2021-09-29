//
// Created by lucas on 9/15/21.
//

#ifndef ADVENTUREGAME_CAMERA_H
#define ADVENTUREGAME_CAMERA_H
#include "../Tools/vd2d.h"
#include "SDL.h"
#include "../Game/Objects/Character_Types/Player.h"

class Camera {
public:
	vd2d pos;
	SDL_Rect* cameraView;
	double zoomFactor {1};

	Camera();

	void move(const Player& p);
};


#endif //ADVENTUREGAME_CAMERA_H
