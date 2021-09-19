//
// Created by lucas on 9/11/21.
//

#include "../hpp/entity.h"


entity::entity(const vd2d &pos, const vd2d &index, const vd2d &indexSize, const vd2d& dimensions, int margin) :pos(pos), index(index), dimensions(dimensions),  indexSize(indexSize), margin(margin) {

}

entity::entity(const vd2d &pos, const vd2d &index) : pos(pos), index(index), indexSize({128,128}), dimensions({128,128}) {

}

entity::entity() {}

void entity::walkRandom(){
	double direction = rand() % 5;


	if(direction == 1) {
		pos.y -= 2;
	}
	if(direction == 2) {
		pos.x += 2;
	}
	if(direction == 3) {
		pos.y += 2;
	}
	if(direction == 4) {
		pos.x -= 2;
	}
}