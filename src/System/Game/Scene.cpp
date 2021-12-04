//
// Created by lucas on 9/12/21.
//

#include "Scene.h"
#include "Game.h"

Scene::Scene(const string& atlasPath) {
	mainAtlas.set(atlasPath);
}

void Scene::fillBlocks(const string &file) {
	blocks = reader.vectorFill(file);
}

void Scene::saveBlocks() {
	reader.vectorWrite(blocks);
}

void Scene::changeBlock(const vd2d &index) {

	blocks[index.x][index.y] = blockStore;


}

void Scene::fillGUI() {
	ui[Scene::main] = (GUI{{

		Entity{{88, 600 - 6 - 92*2}, {3,0}, {32, 32}, {32,32}, 2, 3},

		Entity{{92, 600- 92*2}, {6,0}, {32, 32}, {32,32}, 2},
		Entity{{(92*2)+1, 600- 92*2},{6,0}, {32,32}, {32,32}, 2},
		Entity{{92*3, 600- 92*2}, {6,0}, {32, 32}, {32,32}, 2},

		Entity{{92, 600 - 92}, {6,0}, {32, 32}, {32,32}, 2},
		Entity{{(92*2)+1, 600- 92},{7, 0}, {32,32}, {32,32}, 2},
		Entity{{92*3, 600- 92}, {6,0}, {32, 32}, {32,32}, 2},

		Entity{{92, 600}, {6,0}, {32, 32}, {32,32}, 2},
		Entity{{(92*2)+1, 600},{6, 0}, {32,32}, {32,32}, 2},
		Entity{{92*3, 600}, {6,0}, {32, 32}, {32,32}, 2},

	}
	}
		);

}

void Scene::addPeople(const vd2d &pos, const int& type, const int& team) {
		entities[people].emplace_back(Entity {pos, {(double)type, (double)team}});
}



void Scene::addPeopleRandom(const int &amount) {
	for(int i = 0; i < amount; ++i) {
		entities[people].emplace_back(Entity {{(double)(rand()%2000), (double)(rand()%2000)}, {(11 + (double)(rand() % 6)),(3 + (double)(rand() % 4))}});
	}
}


