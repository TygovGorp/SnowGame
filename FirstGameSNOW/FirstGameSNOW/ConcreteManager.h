#pragma once
#include"Game.h"
#include"Entity.h"
#include"TextureManager.h"
class ConcreteManager
{
public:
	void ConcreteCheck(Entity Player);
	void PlaceConcrete(Entity Player);
	void Update(Entity Player);
	void Render();
private:
	bool ConcreteYN[Game::ScreenSize / Game::gridSize][Game::ScreenSize / Game::gridSize] = { false };
	SDL_Texture* ConcreteTex = TextureManager::LoadTexture("assets/concrete.png");
	SDL_Rect srcRect, destRect;
};

