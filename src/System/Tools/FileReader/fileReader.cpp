//
// Created by lucas on 9/15/21.
//


#include "fileReader.h"


vector<vector<vd2d>> fileReader::vectorFill(const string& file) {
	readStream.open(getDir("scene_data.txt"));
	vector<vector<vd2d>> blockSheet;
	vector<vd2d> blockRow;

	char c1,c2,c3,c4;

	string line;

	if(readStream.is_open()){
			double j,i;

			while(readStream >> c1 >> j >> c2 >> i >> c3 >> c4 ) {
				//dbm(std::to_string(j) + " " + std::to_string(i) + "\n");

						blockRow.push_back({j, i});
				if(c4 == '|') {
					blockSheet.push_back(blockRow);
					blockRow.clear();
				}



			}
		readStream.close();





		return blockSheet;

		} else err("failed to open file");
}

void fileReader::vectorWrite(const vector<vector<vd2d>> &blocks) {
		writeStream.open(getDir("scene_data.txt"));

		char c1,c2,c3,c4;

		string line;

		if(writeStream.is_open()) {
			for(int i = 0 ; i < blocks.size() ; ++i ) {
				for (int k = 0 ; k < blocks[i].size() ; ++k ) {
					writeStream << '[' << blocks[i][k].x << ',' << blocks[i][k].y << ']';
					if(writeStream.bad()) {
						err("writeSteam returned bad");
					}
					if(k == blocks[i].size() -1) {
						writeStream << '|' << '\n';
					} else {
						writeStream << ',';
					}
				}
			}
			writeStream.close();
		} else {
			err("failed to save blocks");
		}

}