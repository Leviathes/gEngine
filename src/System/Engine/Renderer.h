//
// Created by lucas on 9/12/21.
//

#ifndef ADVETUREGAME_RENDERER_H
#define ADVETUREGAME_RENDERER_H
#include "../Tools/common.h"
#include "../Game/Scene.h"
#include "../Game/TextureAtlas.h"
#include "../Tools/FileReader/fileReader.h"
#include "Camera.h"
class Renderer {
	SDL_Renderer* renderer;


	void init();
public:
	Renderer();
	~Renderer();
	Camera view;

	SDL_Renderer* get();
    TTF_Font* fontFPS{nullptr};
	bool set(SDL_Renderer* source);

	void showFrames(const double& frames);
	void showBlockStore(const vd2d& pos, const Scene& cs, const vd2d& index);

	SDL_Texture* loadTexture(const string& path);
	void blit(SDL_Texture* texture, const vd2d& pos);
	void blitBlock(SDL_Texture* texture, const Entity& e);
	void blitEntity(SDL_Texture* texture, const vd2d& index, const vd2d& pos, const vd2d& dimensions, vd2d indexSize = {128,128}, int margin = 64);

	void blitGUI(const Entity& gui, SDL_Texture* texture);
	void renderGUI(const GUI& gui, SDL_Texture* texture);
	/// idk about ALL of these
	void renderTexture();
	void renderSprite();
	void renderEntity(const Entity& entity, SDL_Texture* texture);
	void renderScene(const Scene& scene);
	/// ======================


};


#endif //ADVETUREGAME_RENDERER_H
