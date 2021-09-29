//
// Created by lucas on 9/12/21.
//

#include "Renderer.h"
#include "../Game/Game.h"

Renderer::Renderer() {
	err("TEST");
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Renderer::get() {return renderer;}

bool Renderer::set(SDL_Renderer* source) {
	if(!(renderer = source)) {
		return false;
	} else return true;

}


void Renderer::showFrames(const double& frames) {

		string output{"FPS: "};
		output += std::to_string((Uint32)frames);

		fontFPS = TTF_OpenFont(getDir("Pixer-Regular.ttf").c_str(), 16);
		SDL_Color textColor{0,0,0,0};
		SDL_Surface* textSurface = TTF_RenderText_Solid( fontFPS, output.c_str(), textColor);
		SDL_Texture* fpsTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		blit(fpsTexture, {600, 2});

}

void Renderer::showBlockStore(const vd2d &pos, const Scene& cs, const vd2d& index) {
	//renderEntity({ pos, {cs.blockStore}, {16,16}, {16,16}, {1}}, cs.mainAtlas.Texture);

	SDL_Rect target;


	SDL_Rect clip = {(int)((index.x * 16) + (index.x)), (int)((index.y * 16) + (index.y)), 16, 16};

	target.x = (int)pos.x;
	target.y = (int)pos.y;

	target.h = (int)(64);
	target.w = (int)(64);

	if(SDL_RenderCopy(renderer, cs.mainAtlas.texture, &clip, &target) == -1) {
		err("failed to render Entity");
	}
}


SDL_Texture* Renderer::loadTexture(const string& path) {

	SDL_Texture* texture;
	texture = IMG_LoadTexture(renderer, toolBox::getDir(path).c_str() );
	if(texture == nullptr) {
		err("failed to load Texture.");

	}

	return texture;

}

void Renderer::blit(SDL_Texture *texture, const vd2d& pos) {
	SDL_Rect target;
	target.x = (int)pos.x;
	target.y = (int)pos.y;

	SDL_QueryTexture(texture, nullptr, nullptr, &target.w, &target.h);
	if(texture == nullptr) {
		err("Texture null on load");
	}
	SDL_RenderCopy(renderer, texture, nullptr, &target);

}
void Renderer::blitGUI(const Entity& gui, SDL_Texture* texture) {

	SDL_Rect target;


	SDL_Rect clip = {(int)((gui.getIndex().x * gui.getIndexSize().x) + (gui.getIndex().x * gui.getMargin())) , (int)((gui.getIndex().y * gui.getIndexSize().y) + (gui.getIndex().y * gui.getMargin())), (int)gui.getDimensions().x, (int)gui.getDimensions().y};

	target.x = (int)(gui.getPos().x);
	target.y = (int)(gui.getPos().y);
	target.h = (int)gui.getDimensions().y*3*gui.getScale();
	target.w = (int)gui.getDimensions().x*3*gui.getScale();

	SDL_RenderCopy(renderer, texture, &clip, &target);

}

void Renderer::blitBlock(SDL_Texture* texture, const Entity& e) {

	SDL_Rect target;


	SDL_Rect clip = {(int)((e.getIndex().x * (e.getIndexSize().x)) + (e.getIndex().x ))  , (int)((e.getIndex().y * (e.getIndexSize().y)) + (e.getIndex().y) ),(int)e.getDimensions().x,(int)e.getDimensions().y};

	target.x = (int)((e.getPos().x - view.pos.x) * view.zoomFactor );
	target.y = (int)((e.getPos().y + view.pos.y) * view.zoomFactor );

	target.h = (int)(128*view.zoomFactor);
	target.w = (int)(128*view.zoomFactor);

	SDL_RenderCopy(renderer, texture, &clip, &target);

}



void Renderer::blitEntity(SDL_Texture* texture, const vd2d& index, const vd2d& pos, const vd2d& dimensions ,vd2d indexSize, int margin) {
	SDL_Rect target;


	SDL_Rect clip = {(int)((index.x * indexSize.x) + (index.x * margin)), (int)((index.y * indexSize.y) + (index.y * margin)), (int)dimensions.x, (int)dimensions.y};

	target.x = (int)((pos.x - view.pos.x) * view.zoomFactor );
	target.y = (int)((pos.y + view.pos.y) * view.zoomFactor );

	target.h = (int)(4*dimensions.y*view.zoomFactor);
	target.w = (int)(4*dimensions.x*view.zoomFactor);

	if(SDL_RenderCopy(renderer, texture, &clip, &target) == -1) {
		err("failed to render Entity");
	}
	if(texture == nullptr) {
		err("failed to render Texture");
	}
}


void Renderer::renderGUI(const GUI& gui, SDL_Texture* texture) {
	for(int i = 0; i < gui.widgets.size(); ++i) {
		blitGUI(gui.widgets[i], texture);
	}
}

void Renderer::renderEntity(const Entity& entity, SDL_Texture* texture) {

	blitEntity(texture, entity.getIndex(), entity.getPos(), entity.getDimensions(),{entity.getIndexSize()}, (int)(entity.getMargin()));

}

void Renderer::renderScene(const Scene& scene) {
	for(int i = 0; i < scene.blocks.size(); ++i) {
		for(int j = 0; j < scene.blocks[i].size(); ++j) {

			blitBlock(scene.mainAtlas.texture, {{(double) ((j) * (128) ), (double) ((i) * (128) ) }, {scene.blocks[i][j]}, {16,16}, {16,16}, {1}});
			//blitEntity(Scene.mainAtlas.Texture, {Scene.blocks[i][j]}, {(((double)j * 16) (((double)i * 16) + view.pos.y ) * view.zoomFactor}, {16, 16}, {16,16}, {1});
			//blitBlock(Scene.mainAtlas.Texture, {Scene.blocks[i][j]}, {(((double)j * 128) - view.pos.x) * view.zoomFactor , (((double)i * 128) + view.pos.y ) * view.zoomFactor   } );
		}
	}

	for(int k = 0; k < scene.entities[Scene::people].size(); ++k) {
		renderEntity(scene.entities[Scene::people][k], scene.mainAtlas.texture);
	}
	renderGUI(scene.ui[Scene::main], scene.guiAtlas.texture);


}

