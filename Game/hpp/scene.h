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



	vd2d blockStore{5,2};
	bool spawn{false};



	void fillBlocks(const string& file);
	void saveBlocks();
	void changeBlock(const vd2d& index);
	void fillGUI();
	void addPeople(const vd2d &pos, const int& type = Worker, const int& team = Team_Blue);
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
