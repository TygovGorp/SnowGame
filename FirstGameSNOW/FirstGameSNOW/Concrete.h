#pragma once
#include"Entity.h"
#include"Game.h"
#include"TextureManager.h"
class Concrete
{
public:
	void init(Entity Player);
	void update(Entity Player);
	bool checkDup(Entity Player);
	void render();
private:
	bool ConcreteArr[Game::ScreenSize / Game::gridSize][Game::ScreenSize / Game::gridSize] = { false };
	SDL_Rect srcRect, destRect;
	SDL_Texture* ConcreteTex;
};

