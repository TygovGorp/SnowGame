#pragma once
#include"Game.h"
#include"SDL.h"
class GameClear
{
public:
	void init();
	void update();
	void render();
private:
	SDL_Rect srcRect, destRect;
	SDL_Texture* GameClearTex;
};

