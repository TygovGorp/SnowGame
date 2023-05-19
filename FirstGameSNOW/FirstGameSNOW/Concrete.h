#pragma once
#include"Entity.h"
#include"Game.h"
#include"TextureManager.h"
class Concrete
{
public:
	void init(Entity Player);
	bool checkDup(Entity Player);
	void render();
	int printnum();
private:
	bool ConcreteArr[Game::ScreenSize / Game::gridSize][Game::ScreenSize / Game::gridSize] = { false };
	SDL_Rect srcRect, destRect;
	SDL_Texture* ConcreteTex;
};

