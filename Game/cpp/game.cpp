//
// Created by lucas on 9/11/21.
//

#include "../hpp/game.h"
#include "../Character_Types/hpp/worker.h"
#include "../Character_Types/hpp/king.h"
#include "../Character_Types/hpp/healer.h"
#include "../Character_Types/hpp/fighter.h"
#include "../../System/hpp/engine.h"

game::game() {
	dbm("game constructor");
	if(!init()) {
		err("Failed to init() in game.cpp");
	}
	event = new SDL_Event;
	currentScene = new scene{"tilemap.png"};

}
game::~game() {}



void game::execute() {


	worker w{{10, 10}};
	fighter f {{20,20}};
	healer h {{30,30}};
	king k{{40,40}};



	currentScene->mainAtlas.texture = Renderer.loadTexture("tilemap.png");
	currentScene->guiAtlas.texture = Renderer.loadTexture("interfacePack_32x.png");
	currentScene->fillGUI();
	currentScene->fillBlocks("scene_data.txt");

	currentScene->entities[scene::people].emplace_back(w);
	currentScene->entities[scene::people].emplace_back(f);
	currentScene->entities[scene::people].emplace_back(h);
	currentScene->entities[scene::people].emplace_back(k);

	currentScene->addPeopleRandom({10});
	dbm(std::to_string(currentScene->entities[scene::people].size()));
	dbm("running...");
	dbm("DEBUGGING ON");
	while(!quit()) {

		Uint32 frameTimeStart = SDL_GetTicks();

		SDL_RenderClear(Renderer.get());
		Renderer.renderScene(*currentScene);
		//Renderer.blitBlock(currentScene->mainAtlas.texture, {1,1}, {50,50});
		loop();
		p1.move();
		Uint32 frameTime = SDL_GetTicks() - frameTimeStart;
		frameLimiter(frameTime);
		Renderer.showFrames(1000/(SDL_GetTicks() - frameTimeStart));
		SDL_RenderPresent(Renderer.get());



	}

	dbm("quitting...");
	if(!shiftModifier) {
		currentScene->saveBlocks();
		dbm("saving");
	}

}


void game::handleEvents() {

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

void game::loop() {

	if(currentScene->spawn) {

	}
	handleEvents();
	p1.move();
	Renderer.view.move(p1);
	for(int i = 0; i < currentScene->entities[scene::people].size(); ++i) {
		currentScene->entities[scene::people][i].walkRandom();
	}


		///center
		Renderer.showBlockStore({(100*2)+1, 616- 92}, *currentScene, {currentScene->blockStore.x,currentScene->blockStore.y});
		///domo
		Renderer.showBlockStore({(100*2)+1, 616- 92*2}, *currentScene, {currentScene->blockStore.x,currentScene->blockStore.y-1});
		///mo
		Renderer.showBlockStore({(100*2)+1, 616}, *currentScene, {currentScene->blockStore.x,currentScene->blockStore.y+1});
		///rigmo
		Renderer.showBlockStore({100+8, 616 - 92}, *currentScene, {currentScene->blockStore.x -1,currentScene->blockStore.y});
		///lemo
		Renderer.showBlockStore({(100*3) -8, 616- 92}, *currentScene, {currentScene->blockStore.x +1,currentScene->blockStore.y});
		///bottom rigmo
		Renderer.showBlockStore({100+8, 616- 92*2}, *currentScene, {currentScene->blockStore.x - 1,currentScene->blockStore.y -1});
		///bottom lemo
		Renderer.showBlockStore({100+8, 616}, *currentScene, {currentScene->blockStore.x-1,currentScene->blockStore.y+1});
		///top rigmo
		Renderer.showBlockStore({(100*3)-8, 616- 92*2}, *currentScene, {currentScene->blockStore.x+1,currentScene->blockStore.y-1});
		///top lemo
		Renderer.showBlockStore({(100*3)-8, 616}, *currentScene, {currentScene->blockStore.x+1,currentScene->blockStore.y+1});



}


void game::keyDown(const SDL_KeyboardEvent& e) {
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
				currentScene->blockStore.y = 2;
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

void game::keyUp(const SDL_KeyboardEvent& e) {
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


void game::mouseDown(const SDL_MouseButtonEvent& e) {
	if(e.button == SDL_BUTTON_RIGHT) {

		if(shiftModifier) {


			/// converts screen coordinates to world coordinates
			double Mouse_x = (e.x/Renderer.view.zoomFactor)  + (Renderer.view.pos.x );
			double Mouse_y = (e.y/Renderer.view.zoomFactor)  - (Renderer.view.pos.y );


			double Block_offSet = (128 * Renderer.view.zoomFactor);



			dbm("SHIFT");
		//	cout << Mouse_x << " <= " << (3*(128*Renderer.view.zoomFactor))  - Renderer.view.pos.x<< endl;
		//	cout << Mouse_y << " <= " << (1*(128*Renderer.view.zoomFactor))  + Renderer.view.pos.y<< endl;
			cout << "mouse:"  << Mouse_x << ", " << Mouse_y << endl;
			for (int y = 0; y < currentScene->blocks.size(); ++y) {
				for(int x = 0; x < currentScene->blocks[y].size(); ++x) {

						double Block_x = ((x) * (128 * Renderer.view.zoomFactor) ) ;
						double Block_y = ((y+1) * (128 * (Renderer.view.zoomFactor)) ) ;



					if(Mouse_x * Renderer.view.zoomFactor < (Block_x + Block_offSet ) ){
						if(Mouse_x > Block_x / Renderer.view.zoomFactor  ) {
							if(Mouse_y * Renderer.view.zoomFactor > Block_y - Block_offSet ) {
								if(Mouse_y < Block_y / Renderer.view.zoomFactor ) {

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
			currentScene->addPeople({(double) ((e.x / Renderer.view.zoomFactor) - 20 + Renderer.view.pos.x),
									      (double) ((e.y / Renderer.view.zoomFactor) - 20 - Renderer.view.pos.y)});
			///

			std::cout << "path: " << getDir("");

			std::cout << currentScene->entities[scene::people].size() << ": "
					  << currentScene->entities[scene::people][currentScene->entities[scene::people].size() -
															   1].getPos().x << ", "
					  << currentScene->entities[scene::people][currentScene->entities[scene::people].size() -
															   1].getPos().y;
			cout << " {"
				 << currentScene->entities[scene::people][currentScene->entities[scene::people].size() - 1].getIndex().x
				 << ", "
				 << currentScene->entities[scene::people][currentScene->entities[scene::people].size() - 1].getIndex().y
				 << "}" << endl;
		}
	}
	if(e.button == SDL_BUTTON_LEFT) {
		if(e.clicks == 2) {
			cout << e.x << " " << e.y << endl;
			for(int i = 0; i < currentScene->entities[scene::people].size(); ++i) {
				if(e.x - Renderer.view.pos.x > (currentScene->entities[scene::people][i].getPos().x +20) && e.x - Renderer.view.pos.x < currentScene->entities[scene::people][i].getPos().x + 90) {
					if(e.y -Renderer.view.pos.y>  (currentScene->entities[scene::people][i].getPos().y +20) && e.y - Renderer.view.pos.y< currentScene->entities[scene::people][i].getPos().y + 94) {
					currentScene->entities[scene::people].erase(currentScene->entities[scene::people].begin()+i);
					}
				}
			}
		}
	}

}

void game::mouseUp(const SDL_MouseButtonEvent& e) {

}

void game::mouseWheelUp(SDL_MouseWheelEvent &e) {
	if (e.y > 0) {
		if(Renderer.view.zoomFactor < 3) {
			Renderer.view.zoomFactor += 0.250;
		}

	}
	if(e.y < 0) {
		if(Renderer.view.zoomFactor > 0.4) {
			Renderer.view.zoomFactor -= 0.250;
		}
	}
}

void game::mouseMotion(const SDL_MouseMotionEvent &e) {

	mousePos.x = e.x;
	mousePos.y = e.y;



}

