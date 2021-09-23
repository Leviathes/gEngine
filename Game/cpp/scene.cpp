//
// Created by lucas on 9/12/21.
//

#include "../hpp/scene.h"
#include "../hpp/game.h"

scene::scene(const string& atlasPath) {
	mainAtlas.set(atlasPath);
}

void scene::fillBlocks(const string &file) {
	blocks = reader.vectorFill(file);
}

void scene::fillGUI() {
	ui[scene::main] = (GUI{
		{entity{{92, 600}, {4,4}, {32, 32}, {32,32}, 2},
		 entity{{(92*2)+1, 600},{5, 4}, {32,32}, {32,32}, 2},
		 entity{{92*3, 600},{5, 4}, {32,32}, {32,32}, 2},
		 entity{{92*4, 600},{5, 4}, {32,32}, {32,32}, 2},
		 entity{{92*5, 600},{5, 4}, {32,32}, {32,32}, 2},
		entity{{92*6, 600}, {6,4}, {32, 32}, {32,32}, 2},
	}
	}
		);

}

void scene::addPeople(const int& amount, const vd2d &pos) {
	for(int i = 0; i < amount; ++i) {
		entities[people].emplace_back(entity {pos, {(11 + (double)(rand() % 6)),(3 + (double)(rand() % 4))}});
	}
}

void scene::addPeopleRandom(const int &amount) {
	for(int i = 0; i < amount; ++i) {
		entities[people].emplace_back(entity {{(double)(rand()%10000), (double)(rand()%10000)}, {(11 + (double)(rand() % 6)),(3 + (double)(rand() % 4))}});
	}
}