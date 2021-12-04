//
// Created by lucas on 9/15/21.
//

#include "Camera.h"


Camera::Camera() : pos({-50,-50}) {
	cameraView = new SDL_Rect;
}

void Camera::move(const Player& p) {
	pos = p.getPos();

}