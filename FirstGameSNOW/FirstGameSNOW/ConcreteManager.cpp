#include "ConcreteManager.h"
Concrete** ConcreteManager::init(Entity Player)
{
	Concrete** concreteArr= new Concrete*[Game::ScreenSize / Game::gridSize];
	for (int i = 0; i < Game::ScreenSize / Game::gridSize; ++i)
	{
		concreteArr[i] = new Concrete[Game::ScreenSize / Game::gridSize];
		for (int j = 0; j < Game::ScreenSize / Game::gridSize; ++j)
		{
			concreteArr[i][j] = Concrete();
			concreteArr[i][j].init(Player);
		}
	}
	return concreteArr;
}

void ConcreteManager::update(Entity Player, Concrete** AllConcrete)
{
	snowGone[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize] = true;
	AllConcrete[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize].update(Player);
	gameClear(AllConcrete);
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

void ConcreteManager::gameClear(Concrete** AllConcrete)
{
	int concreteCount = 0;
	for (int i = 0; i < Game::ScreenSize / Game::gridSize; i++)
	{
		for (int j = 0; j < Game::ScreenSize / Game::gridSize; j++)
		{
			if (snowGone[i][j] == true)
			{
				concreteCount++;
			}
		}
	}
	if (concreteCount == Game::ScreenSize / Game::gridSize * Game::ScreenSize / Game::gridSize)
	{
		concreteGameClear = true;
	}
}