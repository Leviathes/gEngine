//
// Created by lucas on 9/13/21.
//
#include "../Game/Game.h"
#include "ToolBox.h"


extern Game g;
namespace toolBox {


	std::string getDir(const std::string &dir) {



		const char PATH_STEP = '/';


		static std::string baseRes;
		if (baseRes.empty()) {
			char *basePath = SDL_GetBasePath();
			if (basePath) {
				baseRes = basePath;
				SDL_free(basePath);
			} else {
				std::cerr << "error getting resource path. Error: " << SDL_GetError() << std::endl;
				return "";
			}
			size_t pos = baseRes.rfind("bin");

			baseRes = baseRes.substr(0, pos) + "assets" + PATH_STEP;

		}

		return dir.empty() ? baseRes : baseRes + dir;
	}

	void printHelp() {
		printHelp(help());
		printHelp(run());
		printHelp(deBug());
	}




	void printHelp(const std::string &helpCommand) {
		if (helpCommand == run()) {
			cout << runHelp;
		}
		if (helpCommand == deBug()) {
			cout << deBugHelp;
		}
		if (helpCommand == help()) {
			cout << helpHelp;
		}

	}


	void err(const std::string &message) {

		if (DBmode == true) {
			std::cerr << "ERROR: " << message << " -- " << SDL_GetError() << std::endl;
		} else return void();

	}

	void dbm(const std::string &message) {
		if (DBmode) {
			cout << message << endl;
		} else return void();
	}


	void handleArgs(int& argc, char *argv[], Game& g) {
		static int i = 1;

		if(argc < 2) {

			g.execute();
			return;
		} else {

			while (i<argc) {
				if ((string) argv[i]==help()) {
					if (argc>i+1) {
						printHelp((string) argv[i+1]);
					}
					else {
						toolBox::printHelp();
					}
					return;

				}
				if ((string) argv[i]=="-r") {
					if (argc>i+1) {
						if ((string) argv[i+1]=="--d") {
							DBmode = true;
						}
					}
					g.execute();
				}
				if ((string) argv[i]=="--d") {
					DBmode = true;
				}
				else {
					DBmode = false;
				}

				i += 1;
			}
		}
	}
}