#include "ConcreteManager.h"
Concrete** ConcreteManager::init()
{
	Concrete** concreteArr= new Concrete*[Game::ScreenSize / Game::gridSize];
	for (int i = 0; i < Game::ScreenSize / Game::gridSize; ++i)
	{
		concreteArr[i] = new Concrete[Game::ScreenSize / Game::gridSize];
		for (int j = 0; j < Game::ScreenSize / Game::gridSize; ++j)
		{
			concreteArr[i][j] = Concrete();
		}
	}
	return concreteArr;
}

void ConcreteManager::update(Entity Player, Concrete** AllConcrete)
{
	snowGone[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize] = true;
	AllConcrete[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize].init(Player);
}

void ConcreteManager::render(Entity Player, Concrete** AllConcrete)
{
	for (int i = 0; i < Game::ScreenSize/Game::gridSize; i++)
	{
		for (int j = 0; j < Game::ScreenSize / Game::gridSize; j++)
		{
			if (snowGone[i][j] == true)
			{
				AllConcrete[i][j].render();
			}
		}
	}
}