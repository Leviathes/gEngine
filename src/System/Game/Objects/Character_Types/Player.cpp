//
// Created by lucas on 9/15/21.
//

#include "Player.h"



Player::Player() {
	up = false;
	down = false;
	left = false;
	right = false;
}

void Player::move() {
	if (up) {pos.y += 5;}
	if (down) {pos.y -= 5;}
	if (left) {pos.x -= 5;}
	if (right) {pos.x += 5;}
}