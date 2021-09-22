//
// Created by lucas on 9/22/21.
//

#include "../hpp/fighter.h"

fighter::fighter(const vd2d &pos) {
	setPos(pos);
	setIndex({Fighter + (double)armorState, team});
}