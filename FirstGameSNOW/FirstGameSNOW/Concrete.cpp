#include "Concrete.h"

void Concrete::init(Entity Player)
{
	ConcreteTex = TextureManager::LoadTexture("assets/concrete.png");
	destRect = { Player.EntityLocX, Player.EntityLocY, Game::gridSize, Game::gridSize };
	srcRect = { 0, 0, 32, 32 };
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

int Concrete::printnum()
{
	return 1;
}