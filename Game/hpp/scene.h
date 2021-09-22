//
// Created by lucas on 9/12/21.
//

#ifndef ADVETUREGAME_SCENE_H
#define ADVETUREGAME_SCENE_H
#include "entity.h"
#include "../../FileReader/hpp/fileReader.h"
#include "GUI.h"



class scene {
public:
	textureAtlas mainAtlas;
	textureAtlas guiAtlas;
	fileReader reader;
	vector<vector<vd2d>> blocks {};
	vector<vector<entity>> entities{{},{},{}};
	vector<GUI> ui{{}, {}, {}};


	bool spawn{false};



	void fillBlocks(const string& file);
	void fillGUI();
	void addPeople(const int& amount, const vd2d &pos);
	void addPeopleRandom(const int& amount);
	scene(const string& atlasPath);


	enum Entity_Types {
		people,
		buildings,
		resources
	};

	enum GUI_Types{
		system,
		inventory,
		main
	};


};


#endif //ADVETUREGAME_SCENE_H
