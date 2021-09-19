//
// Created by lucas on 9/12/21.
//

#ifndef ADVETUREGAME_RENDERER_H
#define ADVETUREGAME_RENDERER_H
#include "common.h"
#include "../../Game/hpp/scene.h"
#include "textureAtlas.h"
#include "../../FileReader/hpp/fileReader.h"
#include "camera.h"
class renderer {
	SDL_Renderer* Renderer;


	void init();
public:
	renderer();
	~renderer();
	camera view;

	SDL_Renderer* get();
    TTF_Font* fontFPS{nullptr};
	bool set(SDL_Renderer* source);

	void showFrames(const double& frames);

	SDL_Texture* loadTexture(const string& path);
	void blit(SDL_Texture* texture, const vd2d& pos);
	void blitBlock(SDL_Texture* texture, const vd2d& index, const vd2d& pos);
	void blitEntity(SDL_Texture* texture, const vd2d& index, const vd2d& pos, const vd2d& dimensions, vd2d indexSize = {128,128}, int margin = 64);
	void blitGUI(const entity& gui, SDL_Texture* texture);
	void renderGUI(const GUI& gui, SDL_Texture* texture);
	/// idk about ALL of these
	void renderTexture();
	void renderSprite();
	void renderEntity(const entity& entity, SDL_Texture* texture);
	void renderScene(const scene& scene);
	/// ======================


};


#endif //ADVETUREGAME_RENDERER_H
