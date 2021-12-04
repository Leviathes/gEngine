//
// Created by lucas on 9/22/21.
//

#ifndef ADVENTUREGAME_HEALER_H
#define ADVENTUREGAME_HEALER_H
#include "Entity.h"

class Healer : public Entity {
public:
	double team = {BLUE_TEAM};
	explicit Healer(const vd2d& pos);

};


#endif //ADVENTUREGAME_HEALER_H
