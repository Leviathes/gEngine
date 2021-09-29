//
// Created by lucas on 9/22/21.
//

#include "Healer.h"


Healer::Healer(const vd2d &pos) {
	setPos(pos);
	setIndex({HEALER, team});
}