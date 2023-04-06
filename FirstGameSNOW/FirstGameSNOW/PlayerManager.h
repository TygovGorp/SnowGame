#pragma once
#include"EnityManager.h"

class PlayerManager : public EnityManager
{
public:
	void init();
	void update(SDL_Rect destRect, SDL_Rect srcRect);
	void render(SDL_Rect destRect, SDL_Rect srcRect);
	void clean();

	/*
	int playerX;
	int playerY;
	*/
	static SDL_Texture* playerTex;
private:
	
};
