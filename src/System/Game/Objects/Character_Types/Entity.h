//
// Created by lucas on 9/11/21.
//

#ifndef ADVETUREGAME_ENTITY_H
#define ADVETUREGAME_ENTITY_H
#include "../../../Tools/common.h"

class Entity {
public:
	vd2d getPos() const;
	vd2d getDimensions()const ;
	vd2d getIndex() const;
	vd2d getIndexSize() const;
	int getMargin() const;
	int getScale() const;
	void walkRandom();
	Entity(const vd2d& pos, const vd2d& index, const vd2d& indexSize, const vd2d& dimensions, int margin, int scale =1);
	Entity(const vd2d& pos, const vd2d& index);
	Entity();
protected:
	vd2d pos;
	vd2d dimensions = {16, 16} ;
	vd2d index;
	vd2d indexSize = {16,16};
	int scale = {1};
	int margin = {1};

	string filename;




    void setPos(const vd2d& p);
    void setDimensions(const vd2d& d);
    void setIndex(const vd2d& i);
    void setIndexSize(const vd2d& is);
    void setMargin(const int& m);








};


#endif //ADVETUREGAME_ENTITY_H
