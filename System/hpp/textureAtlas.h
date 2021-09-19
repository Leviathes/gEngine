//
// Created by lucas on 9/12/21.
//

#ifndef ADVETUREGAME_SPRITESHEET_H
#define ADVETUREGAME_SPRITESHEET_H
#include "common.h"


class textureAtlas {

const int bHeight{128};
const int bWidth{128};
std::string filePath;

public:

	bool set(const string& path);

	SDL_Texture* texture;

};


#endif //ADVETUREGAME_SPRITESHEET_H
