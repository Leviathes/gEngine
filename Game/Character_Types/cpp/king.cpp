//
// Created by lucas on 9/22/21.
//

#include "../hpp/king.h"


king::king(const vd2d& pos) {
	setPos(pos);
	setIndex({King, team});
}