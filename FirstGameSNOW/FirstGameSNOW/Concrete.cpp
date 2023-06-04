#include "Concrete.h"

void Concrete::init(Entity Player)
{
	
}

void Concrete::update(Entity Player)
{
	if (ConcreteTex)
	{

	}
	else
	{
		ConcreteTex = TextureManager::LoadTexture("assets/concrete.png");
	}
	srcRect = { 0, 0, 32, 32 };
	destRect = { Player.EntityLocX, Player.EntityLocY, Game::gridSize, Game::gridSize };
}

bool Concrete::checkDup(Entity Player)
{
	if (ConcreteArr[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize] == false)
	{
		destRect = { Player.EntityLocX, Player.EntityLocY, Game::gridSize, Game::gridSize };
		ConcreteArr[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize] = true;
		return false;
	}
	else
	{
		return true;
	}

}

void Concrete::render()
{
	TextureManager::Draw(ConcreteTex, srcRect, destRect);
}