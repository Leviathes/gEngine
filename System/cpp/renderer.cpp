//
// Created by lucas on 9/12/21.
//

#include "../hpp/renderer.h"
#include "../../Game/hpp/game.h"

renderer::renderer() {
	err("TEST");
}

renderer::~renderer() {
	SDL_DestroyRenderer(Renderer);
}

SDL_Renderer* renderer::get() {return Renderer;}

bool renderer::set(SDL_Renderer* source) {
	if(!(Renderer = source)) {
		return false;
	} else return true;

}


void renderer::showFrames(const double& frames) {

		string output{"FPS: "};
		output += std::to_string((Uint32)frames);

		fontFPS = TTF_OpenFont(getDir("Pixer-Regular.ttf").c_str(), 16);
		SDL_Color textColor{0,0,0,0};
		SDL_Surface* textSurface = TTF_RenderText_Solid( fontFPS, output.c_str(), textColor);
		SDL_Texture* fpsTexture = SDL_CreateTextureFromSurface(Renderer, textSurface);
		blit(fpsTexture, {600, 2});

}


SDL_Texture* renderer::loadTexture(const string& path) {

	SDL_Texture* texture;
	texture = IMG_LoadTexture(Renderer, toolBox::getDir(path).c_str() );
	if(texture == nullptr) {
		err("failed to load texture.");

	}

	return texture;

}

void renderer::blit(SDL_Texture *texture, const vd2d& pos) {
	SDL_Rect target;
	target.x = (int)pos.x;
	target.y = (int)pos.y;

	SDL_QueryTexture(texture, nullptr, nullptr, &target.w, &target.h);
	if(texture == nullptr) {
		err("texture null on load");
	}
	SDL_RenderCopy(Renderer, texture, nullptr, &target);

}

void renderer::blitBlock(SDL_Texture* texture, const vd2d& index, const vd2d& pos) {

	SDL_Rect target;


	SDL_Rect clip = {(int)((index.x * (16)) + (index.x))  , (int)((index.y * (16)) + (index.y)),16,16};

	target.x = (int)pos.x;
	target.y = (int)pos.y;

	target.h = (int)(128*view.zoomFactor);
	target.w = (int)(128*view.zoomFactor);

	SDL_RenderCopy(Renderer, texture, &clip, &target);

}

void renderer::blitEntity(SDL_Texture* texture, const vd2d& index, const vd2d& pos, const vd2d& dimensions ,vd2d indexSize, int margin) {
	SDL_Rect target;


	SDL_Rect clip = {(int)((index.x * indexSize.x) + (index.x * margin)), (int)((index.y * indexSize.y) + (index.y * margin)), (int)dimensions.x, (int)dimensions.y};

	target.x = (int)((pos.x - view.pos.x) * view.zoomFactor );
	target.y = (int)((pos.y + view.pos.y) * view.zoomFactor );
	target.h = (int)(3*dimensions.y*view.zoomFactor);
	target.w = (int)(3*dimensions.x*view.zoomFactor);

	if(SDL_RenderCopy(Renderer, texture, &clip, &target) == -1) {
		err("failed to render entity");
	}
	if(texture == nullptr) {
		err("failed to render texture");
	}
}

void renderer::blitGUI(const entity& gui, SDL_Texture* texture) {

	SDL_Rect target;


SDL_Rect clip = {(int)((gui.getIndex().x * gui.getIndexSize().x) + (gui.getIndex().x * gui.getMargin())) , (int)((gui.getIndex().y * gui.getIndexSize().y) + (gui.getIndex().y * gui.getMargin())), (int)gui.getDimensions().x, (int)gui.getDimensions().y};

target.x = (int)(gui.getPos().x);
target.y = (int)(gui.getPos().y);
target.h = (int)gui.getDimensions().y*3;
target.w = (int)gui.getDimensions().x*3;

SDL_RenderCopy(Renderer, texture, &clip, &target);

}

void renderer::renderGUI(const GUI& gui, SDL_Texture* texture) {
	for(int i = 0; i < gui.widgets.size(); ++i) {
		blitGUI(gui.widgets[i], texture);
	}
}

void renderer::renderEntity(const entity& entity, SDL_Texture* texture) {

	blitEntity(texture, entity.getIndex(), entity.getPos(), entity.getDimensions(),{entity.getIndexSize()}, (int)(entity.getMargin()));

}

void renderer::renderScene(const scene& scene) {
	for(int i = 0; i < scene.blocks.size(); ++i) {
		for(int j = 0; j < scene.blocks[i].size(); ++j) {
			blitBlock(scene.mainAtlas.texture, {scene.blocks[i][j]}, {(((double)j * 128) - view.pos.x) * view.zoomFactor , (((double)i * 128) + view.pos.y ) * view.zoomFactor   } );
		}
	}

	for(int k = 0; k < scene.entities[scene::people].size(); ++k) {
		renderEntity(scene.entities[scene::people][k], scene.mainAtlas.texture);
	}
	renderGUI(scene.ui[scene::main], scene.guiAtlas.texture);


}

