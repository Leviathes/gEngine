//
// Created by lucas on 9/22/21.
//

#include "Fighter.h"

Fighter::Fighter(const vd2d &pos) {
	setPos(pos);
	setIndex({FIGHTER + (double)armorState, team});
}