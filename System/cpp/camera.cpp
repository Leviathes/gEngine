//
// Created by lucas on 9/15/21.
//

#include "../hpp/camera.h"


camera::camera() : pos({-50,-50}) {
	cameraView = new SDL_Rect;
}

void camera::move(const player& p) {
	pos = p.getPos();

}