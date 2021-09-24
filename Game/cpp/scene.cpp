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

void scene::saveBlocks() {
	reader.vectorWrite(blocks);
}

void scene::changeBlock(const vd2d &index) {

	blocks[index.x][index.y] = blockStore;


}

void scene::fillGUI() {
	ui[scene::main] = (GUI{{

		entity{{88, 600 - 6 - 92*2}, {3,0}, {32, 32}, {32,32}, 2, 3},

		entity{{92, 600- 92*2}, {6,0}, {32, 32}, {32,32}, 2},
		entity{{(92*2)+1, 600- 92*2},{6,0}, {32,32}, {32,32}, 2},
		entity{{92*3, 600- 92*2}, {6,0}, {32, 32}, {32,32}, 2},

		entity{{92, 600 - 92}, {6,0}, {32, 32}, {32,32}, 2},
		entity{{(92*2)+1, 600- 92},{7, 0}, {32,32}, {32,32}, 2},
		entity{{92*3, 600- 92}, {6,0}, {32, 32}, {32,32}, 2},

		entity{{92, 600}, {6,0}, {32, 32}, {32,32}, 2},
		entity{{(92*2)+1, 600},{6, 0}, {32,32}, {32,32}, 2},
		entity{{92*3, 600}, {6,0}, {32, 32}, {32,32}, 2},

	}
	}
		);

}

void scene::addPeople(const vd2d &pos, const int& type, const int& team) {
		entities[people].emplace_back(entity {pos, {(double)type, (double)team}});
}



void scene::addPeopleRandom(const int &amount) {
	for(int i = 0; i < amount; ++i) {
		entities[people].emplace_back(entity {{(double)(rand()%2000), (double)(rand()%2000)}, {(11 + (double)(rand() % 6)),(3 + (double)(rand() % 4))}});
	}
}


