#include "ConcreteManager.h"
void ConcreteManager::update(Entity Player)
{
	/* WORK IN PROGRESS
	if (checkDup(Player) == false)
	{

	}
	*/
	concreteArr[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize] = *new Concrete();
	concreteArr[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize].init(Player);
}

void ConcreteManager::render(Entity Player)
{
	concreteArr[Player.EntityLocX / Game::gridSize][Player.EntityLocY / Game::gridSize].render();
}