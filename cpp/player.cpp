//
// Created by lucas on 9/15/21.
//

#include "../hpp/player.h"



player::player() {
	up = false;
	down = false;
	left = false;
	right = false;
}

void player::move() {
	if (up) {pos.y += 3;}
	if (down) {pos.y -= 3;}
	if (left) {pos.x += 3;}
	if (right) {pos.x -= 3;}
}