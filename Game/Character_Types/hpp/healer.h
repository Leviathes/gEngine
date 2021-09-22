//
// Created by lucas on 9/22/21.
//

#ifndef ADVENTUREGAME_HEALER_H
#define ADVENTUREGAME_HEALER_H
#include "../../hpp/entity.h"

class healer : public entity {
public:
	double team = {Team_Blue};
	explicit healer(const vd2d& pos);

};


#endif //ADVENTUREGAME_HEALER_H
