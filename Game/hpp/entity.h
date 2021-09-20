//
// Created by lucas on 9/11/21.
//

#ifndef ADVETUREGAME_ENTITY_H
#define ADVETUREGAME_ENTITY_H
#include "../../System/hpp/common.h"
#include "../../System/hpp/texture.h"

class entity {
public:
	vd2d pos;
	vd2d dimensions;
	vd2d index;
	vd2d indexSize;
	int margin;

	string filename;
public:

    vd2d getPos();
    vd2d getDimensions();
    vd2d getIndex();
    vd2d getIndexSize();
    int getMargin();

    void setPos(const vd2d& p);
    void setDimensions(const vd2d& d);
    void setIndex(const vd2d& i);
    void setIndexSize(const vd2d& is);
    void setMargin(const vd2d& m);

protected:

	entity(const vd2d& pos, const vd2d& index, const vd2d& indexSize, const vd2d& dimensions, int margin);
	entity(const vd2d& pos, const vd2d& index);
	entity();

	void walkRandom();




};


#endif //ADVETUREGAME_ENTITY_H
