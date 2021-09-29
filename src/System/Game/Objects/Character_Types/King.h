//
// Created by lucas on 9/22/21.
//

#ifndef ADVENTUREGAME_KING_H
#define ADVENTUREGAME_KING_H
#include "Entity.h"

class King : public Entity {

public:
	double team = {BLUE_TEAM};
	explicit King(const vd2d& pos);

};


#endif //ADVENTUREGAME_KING_H
