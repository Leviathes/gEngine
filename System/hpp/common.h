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
#include "toolBox.h"

using std::cout, std::cin, std::endl, std::vector, std::string;
using namespace toolBox;


const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH  = 1280;


/// - console argument string literals

const string help = "-h";
const string run  = "-r";
const string deBug = "--d";

// Description strings

const string helpHelp  = "[  -h ] ... use to get help about arguments to pass into the CLI\n";
const string runHelp   = "[  -r ] ... This will execute the main game program\n";
const string deBugHelp = "[ --d ] ... use to set the DBmode to true. set to false by defualt. If true Debugging api calls will be enabled\n";


#endif //ADVETUREGAME_COMMON_H
