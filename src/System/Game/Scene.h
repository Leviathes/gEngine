//
// Created by lucas on 9/12/21.
//

#ifndef ADVETUREGAME_SCENE_H
#define ADVETUREGAME_SCENE_H
#include "Objects/Character_Types/Entity.h"
#include "TextureAtlas.h"
#include "../Tools/FileReader/fileReader.h"
#include "GUI/GUI.h"



class Scene {
public:
	TextureAtlas mainAtlas;
	TextureAtlas guiAtlas;
	fileReader reader;
	vector<vector<vd2d>> blocks {};
	vector<vector<Entity>> entities{{},{},{}};
	vector<GUI> ui{{}, {}, {}};



	vd2d blockStore{5,2};
	bool spawn{false};



	void fillBlocks(const string& file);
	void saveBlocks();
	void changeBlock(const vd2d& index);
	void fillGUI();
	void addPeople(const vd2d &pos, const int& type = WORKER, const int& team = BLUE_TEAM);
	void addPeopleRandom(const int& amount);
	Scene(const string& atlasPath);


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
