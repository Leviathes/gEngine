//
// Created by lucas on 9/22/21.
//

#ifndef ADVENTUREGAME_KING_H
#define ADVENTUREGAME_KING_H
#include "../../hpp/entity.h"

class king : public entity {

public:
	double team = {Team_Blue};
	explicit king(const vd2d& pos);

};


#endif //ADVENTUREGAME_KING_H
