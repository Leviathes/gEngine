//
// Created by lucas on 9/11/21.
//

#ifndef ADVETUREGAME_ENTITY_H
#define ADVETUREGAME_ENTITY_H
#include "../../System/hpp/common.h"
#include "../../System/hpp/texture.h"

class entity {
public:
	vd2d getPos() const;
	vd2d getDimensions()const ;
	vd2d getIndex() const;
	vd2d getIndexSize() const;
	int getMargin() const;
	void walkRandom();
	entity(const vd2d& pos, const vd2d& index, const vd2d& indexSize, const vd2d& dimensions, int margin);
	entity(const vd2d& pos, const vd2d& index);
	entity();
protected:
	vd2d pos;
	vd2d dimensions;
	vd2d index;
	vd2d indexSize = {16,16};
	int margin = {1};

	string filename;




    void setPos(const vd2d& p);
    void setDimensions(const vd2d& d);
    void setIndex(const vd2d& i);
    void setIndexSize(const vd2d& is);
    void setMargin(const int& m);








};


#endif //ADVETUREGAME_ENTITY_H
