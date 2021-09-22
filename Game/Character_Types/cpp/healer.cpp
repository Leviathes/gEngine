//
// Created by lucas on 9/22/21.
//

#include "../hpp/healer.h"


healer::healer(const vd2d &pos) {
	setPos(pos);
	setIndex({Healer, team});
}