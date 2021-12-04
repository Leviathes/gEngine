//
// Created by lucas on 9/15/21.
//

#ifndef ADVENTUREGAME_FILEREADER_H
#define ADVENTUREGAME_FILEREADER_H
#include "../common.h"
#include <iostream>
#include <fstream>
#include <sstream>

class fileReader {

public:
	std::ifstream readStream;
	std::ofstream writeStream;




	vector<vector<vd2d>> vectorFill(const string& file);
	void vectorWrite(const vector<vector<vd2d>>& blocks);

};


#endif //ADVENTUREGAME_FILEREADER_H
