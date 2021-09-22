//
// Created by lucas on 9/22/21.
//

#ifndef ADVENTUREGAME_FIGHTER_H
#define ADVENTUREGAME_FIGHTER_H
#include "../../hpp/entity.h"

class fighter : public entity {
public:
	double team = {Team_Blue};
	explicit fighter(const vd2d& pos);
	bool armorState = {false};


};


#endif //ADVENTUREGAME_FIGHTER_H
