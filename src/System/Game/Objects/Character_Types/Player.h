//
// Created by lucas on 9/15/21.
//

#ifndef ADVENTUREGAME_PLAYER_H
#define ADVENTUREGAME_PLAYER_H
#include "Entity.h"

class Player : public Entity{

public:
	Player();
	bool up,down,left,right;
	void move();

};


#endif //ADVENTUREGAME_PLAYER_H
