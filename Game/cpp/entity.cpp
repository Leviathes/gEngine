//
// Created by lucas on 9/11/21.
//

#include "../hpp/entity.h"



vd2d entity::getPos() const { return pos; }
vd2d entity::getDimensions() const { return dimensions; }
vd2d entity::getIndex() const {return index;}
vd2d entity::getIndexSize() const {return indexSize;}
int entity::getMargin() const {return margin;}
int entity::getScale() const {return scale;}

void entity::setPos(const vd2d& p) {
	pos = p;
}

void entity::setDimensions(const vd2d &d) {
	dimensions = d;
}

void entity::setIndex(const vd2d &i) {
	index = i;
}

void entity::setIndexSize(const vd2d &is) {
	indexSize = is;
}

void entity::setMargin(const int &m) {
	margin = m;
}

entity::entity(const vd2d &pos, const vd2d &index, const vd2d &indexSize, const vd2d& dimensions, int margin, int scale) :pos(pos), index(index), dimensions(dimensions),  indexSize(indexSize), margin(margin), scale(scale) {

}

entity::entity(const vd2d &pos, const vd2d &index) : pos(pos), index(index), indexSize({16,16}), dimensions({16,16}), margin(1) {

}

entity::entity() : indexSize({ 16, 16 }), dimensions({ 16, 16 }), margin(1) {}

void entity::walkRandom(){
	double direction = rand() % 5;


	if(direction == 1) {
		pos.y -= .5;
	}
	if(direction == 2) {
		pos.x += .5;
	}
	if(direction == 3) {
		pos.y += .5;
	}
	if(direction == 4) {
		pos.x -= .5;
	}
}