//
// Created by lucas on 9/15/21.
//

#ifndef ADVENTUREGAME_FILEREADER_H
#define ADVENTUREGAME_FILEREADER_H
#include "../../System/hpp/common.h"
#include <fstream>
#include <sstream>

class fileReader {

public:
	std::ifstream vectorFile;


	void read();
	vector<vector<vd2d>> vectorFill(const string& file);


};


#endif //ADVENTUREGAME_FILEREADER_H
