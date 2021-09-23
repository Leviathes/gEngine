#include <iostream>

#include "../../System/hpp/common.h"
#include "../hpp/game.h"





static game game;

int main(int argc, char* argv[]) {
	dbm("HELLO??\n");
	handleArgs(argc, argv, game);

	return 0;
}

