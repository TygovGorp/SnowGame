#include "ConcreteManager.h"


void ConcreteManager::ConcreteCheck(Entity Player)
{
	
}

void ConcreteManager::PlaceConcrete(Entity Player)
{
	
	
	if (ConcreteYN[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize] == false)
	{
		ConcreteYN[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize] = true;
		Update(Player);
	}
	
}

void ConcreteManager::Update(Entity Player)
{
	destRect = {Player.EntityLocX, Player.EntityLocY, Game::gridSize, Game::gridSize };
	srcRect = { 0, 0, 32, 32 };
}

void ConcreteManager::Render()
{
	TextureManager::Draw(ConcreteTex, srcRect, destRect);
}