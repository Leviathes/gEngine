//
// Created by lucas on 9/11/21.
//

#ifndef ADVETUREGAME_ENTITY_H
#define ADVETUREGAME_ENTITY_H
#include "common.h"
#include "texture.h"

class entity {
public:
	vd2d pos;
	vd2d dimensions;
	vd2d index;
	vd2d indexSize;
	int margin;

	string filename;


	entity(const vd2d& pos, const vd2d& index, const vd2d& indexSize, const vd2d& dimensions, int margin);
	entity(const vd2d& pos, const vd2d& index);
	entity();

	void walkRandom();




};


#endif //ADVETUREGAME_ENTITY_H
