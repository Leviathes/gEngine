//
// Created by lucas on 9/11/21.
//

#include "Game.h"
#include "Objects/Character_Types/Worker.h"
#include "Objects/Character_Types/King.h"
#include "Objects/Character_Types/Healer.h"
#include "Objects/Character_Types/Fighter.h"
#include "../Engine/Engine.h"

Game::Game() {
	dbm("Game constructor");
	if(!init()) {
		err("Failed to init() in Game.cpp");
	}
	event = new SDL_Event;
	currentScene = new Scene{"tilemap.png"};

}
Game::~Game() {}



void Game::execute() {


	Worker w{{10, 10}};
	Fighter f {{20,20}};
	Healer h {{30,30}};
	King k{{40,40}};



	currentScene->mainAtlas.texture = renderer.loadTexture("tilemap.png");
	currentScene->guiAtlas.texture = renderer.loadTexture("interfacePack_32x.png");
	currentScene->fillGUI();
	currentScene->fillBlocks("scene_data.txt");

	currentScene->entities[Scene::people].emplace_back(w);
	currentScene->entities[Scene::people].emplace_back(f);
	currentScene->entities[Scene::people].emplace_back(h);
	currentScene->entities[Scene::people].emplace_back(k);

	currentScene->addPeopleRandom({10});
	dbm(std::to_string(currentScene->entities[Scene::people].size()));
	dbm("running...");
	dbm("DEBUGGING ON");
	while(!quit()) {

		Uint32 frameTimeStart = SDL_GetTicks();

		SDL_RenderClear(renderer.get());
		renderer.renderScene(*currentScene);
		//renderer.blitBlock(currentScene->mainAtlas.Texture, {1,1}, {50,50});
		loop();
		p1.move();
		Uint32 frameTime = SDL_GetTicks() - frameTimeStart;
		frameLimiter(frameTime);
		renderer.showFrames(1000/(SDL_GetTicks() - frameTimeStart));
		SDL_RenderPresent(renderer.get());



	}

	dbm("quitting...");
	if(!shiftModifier) {
		currentScene->saveBlocks();
		dbm("saving");
	}

}


void Game::handleEvents() {

	while(SDL_PollEvent(event)) {
		if (event->type == SDL_QUIT) {
			quit(true);
		}
		if(event->type == SDL_KEYDOWN) {
			keyDown(event->key);
		}
		if(event->type == SDL_KEYUP) {
			keyUp(event->key);
		}
		if(event->type == SDL_MOUSEBUTTONDOWN){
			mouseDown(event->button);
		}
		if(event->type == SDL_MOUSEBUTTONUP) {
			mouseUp(event->button);
		}
		if(event->type == SDL_MOUSEWHEEL) {
			mouseWheelUp(event->wheel);
		}
		if(event->type == SDL_MOUSEMOTION) {
		 	mouseMotion(event->motion);

		}
	}
}

void Game::loop() {

	if(currentScene->spawn) {

	}
	handleEvents();
	p1.move();
	renderer.view.move(p1);
	for(int i = 0; i < currentScene->entities[Scene::people].size(); ++i) {
		currentScene->entities[Scene::people][i].walkRandom();
	}


		///center
		renderer.showBlockStore({(100*2)+1, 616- 92}, *currentScene, {currentScene->blockStore.x,currentScene->blockStore.y});
		///domo
		renderer.showBlockStore({(100*2)+1, 616- 92*2}, *currentScene, {currentScene->blockStore.x,currentScene->blockStore.y-1});
		///mo
		renderer.showBlockStore({(100*2)+1, 616}, *currentScene, {currentScene->blockStore.x,currentScene->blockStore.y+1});
		///rigmo
		renderer.showBlockStore({100+8, 616 - 92}, *currentScene, {currentScene->blockStore.x -1,currentScene->blockStore.y});
		///lemo
		renderer.showBlockStore({(100*3) -8, 616- 92}, *currentScene, {currentScene->blockStore.x +1,currentScene->blockStore.y});
		///bottom rigmo
		renderer.showBlockStore({100+8, 616- 92*2}, *currentScene, {currentScene->blockStore.x - 1,currentScene->blockStore.y -1});
		///bottom lemo
		renderer.showBlockStore({100+8, 616}, *currentScene, {currentScene->blockStore.x-1,currentScene->blockStore.y+1});
		///top rigmo
		renderer.showBlockStore({(100*3)-8, 616- 92*2}, *currentScene, {currentScene->blockStore.x+1,currentScene->blockStore.y-1});
		///top lemo
		renderer.showBlockStore({(100*3)-8, 616}, *currentScene, {currentScene->blockStore.x+1,currentScene->blockStore.y+1});



}


void Game::keyDown(const SDL_KeyboardEvent& e) {
	if(e.repeat == 0) {
		if(e.keysym.scancode == SDL_SCANCODE_W) {
			p1.up = true;
		}
		if(e.keysym.scancode == SDL_SCANCODE_A) {
			p1.left = true;
		}
		if(e.keysym.scancode == SDL_SCANCODE_S) {
			p1.down = true;
		}
		if(e.keysym.scancode == SDL_SCANCODE_D) {
			p1.right = true;
		}
		if(e.keysym.scancode == SDL_SCANCODE_LSHIFT) {
			shiftModifier = true;
		}
		if(e.keysym.scancode == SDL_SCANCODE_UP) {
			currentScene->blockStore.y -= 1;
			if(currentScene->blockStore.y < 0) {

					currentScene->blockStore.y = 0;

			}
		}
		if(e.keysym.scancode == SDL_SCANCODE_DOWN) {
			currentScene->blockStore.y += 1;
			if(currentScene->blockStore.y > 2) {
				if(currentScene->blockStore.x <3) {

				} else {
					currentScene->blockStore.y = 2;
				}
			}
		}
		if(e.keysym.scancode == SDL_SCANCODE_LEFT) {
			currentScene->blockStore.x -= 1;
			if(currentScene->blockStore.x < 0) {
				currentScene->blockStore.x = 0;
			}
		}
		if(e.keysym.scancode == SDL_SCANCODE_RIGHT) {
			currentScene->blockStore.x += 1;
			if(currentScene->blockStore.x > 9) {
				currentScene->blockStore.x = 9;
			}
		}


	}
}

void Game::keyUp(const SDL_KeyboardEvent& e) {
	if(e.repeat == 0) {
		if(e.keysym.scancode == SDL_SCANCODE_W) {
			p1.up = false;
		}
		if(e.keysym.scancode == SDL_SCANCODE_A) {
			p1.left = false;
		}
		if(e.keysym.scancode == SDL_SCANCODE_S) {
			p1.down = false;
		}
		if(e.keysym.scancode == SDL_SCANCODE_D) {
			p1.right = false;
		}
		if(e.keysym.scancode == SDL_SCANCODE_LSHIFT) {
			shiftModifier = false;
		}

	}
}


void Game::mouseDown(const SDL_MouseButtonEvent& e) {
	if(e.button == SDL_BUTTON_RIGHT) {

		if(shiftModifier) {


			/// converts screen coordinates to world coordinates
			double Mouse_x = (e.x/renderer.view.zoomFactor)  + (renderer.view.pos.x );
			double Mouse_y = (e.y/renderer.view.zoomFactor)  - (renderer.view.pos.y );


			double Block_offSet = (128 * renderer.view.zoomFactor);



			dbm("SHIFT");
		//	cout << Mouse_x << " <= " << (3*(128*renderer.view.zoomFactor))  - renderer.view.pos.x<< endl;
		//	cout << Mouse_y << " <= " << (1*(128*renderer.view.zoomFactor))  + renderer.view.pos.y<< endl;
			cout << "mouse:"  << Mouse_x << ", " << Mouse_y << endl;
			for (int y = 0; y < currentScene->blocks.size(); ++y) {
				for(int x = 0; x < currentScene->blocks[y].size(); ++x) {

						double Block_x = ((x) * (128 * renderer.view.zoomFactor) ) ;
						double Block_y = ((y+1) * (128 * (renderer.view.zoomFactor)) ) ;



					if(Mouse_x * renderer.view.zoomFactor < (Block_x + Block_offSet ) ){
						if(Mouse_x > Block_x / renderer.view.zoomFactor  ) {
							if(Mouse_y * renderer.view.zoomFactor > Block_y - Block_offSet ) {
								if(Mouse_y < Block_y / renderer.view.zoomFactor ) {

									currentScene->changeBlock({(double)y,(double)x});

									cout << "blocck:" << Block_x << ", " << Block_y << endl;
									return;
								}

							}
						}

					}
				}

			}

		} else {

			/// ZOOM AND LOCATION transform equation - Turns screen coord into world coord
			currentScene->addPeople({(double) ((e.x / renderer.view.zoomFactor) - 20 + renderer.view.pos.x),
									      (double) ((e.y / renderer.view.zoomFactor) - 20 - renderer.view.pos.y)});
			///

			std::cout << "path: " << getDir("");

			std::cout << currentScene->entities[Scene::people].size() << ": "
					  << currentScene->entities[Scene::people][currentScene->entities[Scene::people].size() -
															   1].getPos().x << ", "
					  << currentScene->entities[Scene::people][currentScene->entities[Scene::people].size() -
															   1].getPos().y;
			cout << " {"
				 << currentScene->entities[Scene::people][currentScene->entities[Scene::people].size() - 1].getIndex().x
				 << ", "
				 << currentScene->entities[Scene::people][currentScene->entities[Scene::people].size() - 1].getIndex().y
				 << "}" << endl;
		}
	}
	if(e.button == SDL_BUTTON_LEFT) {
		if(e.clicks == 2) {
			cout << e.x << " " << e.y << endl;
			for(int i = 0; i < currentScene->entities[Scene::people].size(); ++i) {
				if(e.x - renderer.view.pos.x > (currentScene->entities[Scene::people][i].getPos().x +20) && e.x - renderer.view.pos.x < currentScene->entities[Scene::people][i].getPos().x + 90) {
					if(e.y -renderer.view.pos.y>  (currentScene->entities[Scene::people][i].getPos().y +20) && e.y - renderer.view.pos.y< currentScene->entities[Scene::people][i].getPos().y + 94) {
					currentScene->entities[Scene::people].erase(currentScene->entities[Scene::people].begin()+i);
					}
				}
			}
		}
	}

}

void Game::mouseUp(const SDL_MouseButtonEvent& e) {

}

void Game::mouseWheelUp(SDL_MouseWheelEvent &e) {
	if (e.y > 0) {
		if(renderer.view.zoomFactor < 3) {
			renderer.view.zoomFactor += 0.250;
		}

	}
	if(e.y < 0) {
		if(renderer.view.zoomFactor > 0.4) {
			renderer.view.zoomFactor -= 0.250;
		}
	}
}

void Game::mouseMotion(const SDL_MouseMotionEvent &e) {

	mousePos.x = e.x;
	mousePos.y = e.y;



}

