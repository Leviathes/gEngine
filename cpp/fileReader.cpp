//
// Created by lucas on 9/15/21.
//


#include "../hpp/fileReader.h"


vector<vector<vd2d>> fileReader::vectorFill(const string& file) {
	vectorFile.open(getDir("scene_data.txt"));
	vector<vector<vd2d>> blockSheet;
	vector<vd2d> blockRow;

	char c1,c2,c3,c4;

	string line;

	if(vectorFile.is_open()){
			double j,i;

			while(vectorFile >> c1 >> j >> c2 >> i >> c3 >> c4 ) {
				//dbm(std::to_string(j) + " " + std::to_string(i) + "\n");

						blockRow.push_back({j, i});
				if(c4 == '|') {
					blockSheet.push_back(blockRow);
					blockRow.clear();
				}



			}
		vectorFile.close();





		return blockSheet;

		} else err("failed to open file");
}