//
// Created by lucas on 9/11/21.
//

#ifndef ADVETUREGAME_COMMON_H
#define ADVETUREGAME_COMMON_H

#include <iostream>
#include <vector>


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#include "vd2d.h"
#include "ToolBox.h"

using std::cout, std::cin, std::endl, std::vector, std::string;
using namespace toolBox;


const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH  = 1280;


/// - console argument string literals

static string help() {
	return"-h";
}
static string run() {
	return" -r";
}
static string deBug(){
	return "--d";
}

// Description strings

static string helpHelp() {
	return "[  -h ] ... use to get help about arguments to pass into the CLI\n";
}
static string runHelp () {
	return "[  -r ] ... This will execute the main Game program\n";
}
static string deBugHelp(){
		return "[ --d ] ... use to set the DBmode to true. set to false by defualt. If true Debugging api calls will be enabled\n";
}


enum Character_Types {
	WORKER = 12,
	HEALER,
	FIGHTER,
	FIGHTER_ARMORED,
	KING
};

enum Teams {
	BLUE_TEAM = 3,
	RED_TEAM,
	GREEN_TEAM,
	GREY_TEAM
};


#endif //ADVETUREGAME_COMMON_H
