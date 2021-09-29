//
// Created by lucas on 9/11/21.
//

#include "Entity.h"



vd2d Entity::getPos() const { return pos; }
vd2d Entity::getDimensions() const { return dimensions; }
vd2d Entity::getIndex() const {return index;}
vd2d Entity::getIndexSize() const {return indexSize;}
int Entity::getMargin() const {return margin;}
int Entity::getScale() const {return scale;}

void Entity::setPos(const vd2d& p) {
	pos = p;
}

void Entity::setDimensions(const vd2d &d) {
	dimensions = d;
}

void Entity::setIndex(const vd2d &i) {
	index = i;
}

void Entity::setIndexSize(const vd2d &is) {
	indexSize = is;
}

void Entity::setMargin(const int &m) {
	margin = m;
}

Entity::Entity(const vd2d &pos, const vd2d &index, const vd2d &indexSize, const vd2d& dimensions, int margin, int scale) :pos(pos), index(index), dimensions(dimensions),  indexSize(indexSize), margin(margin), scale(scale) {

}

Entity::Entity(const vd2d &pos, const vd2d &index) : pos(pos), index(index), indexSize({16,16}), dimensions({16,16}), margin(1) {

}

Entity::Entity() : indexSize({ 16, 16 }), dimensions({ 16, 16 }), margin(1) {}

void Entity::walkRandom(){
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