//
// Created by lucas on 9/22/21.
//

#ifndef ADVENTUREGAME_FIGHTER_H
#define ADVENTUREGAME_FIGHTER_H
#include "Entity.h"

class Fighter : public Entity {
public:
	double team = {BLUE_TEAM};
	explicit Fighter(const vd2d& pos);
	bool armorState = {false};


};


#endif //ADVENTUREGAME_FIGHTER_H
