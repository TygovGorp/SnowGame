#pragma once
#include"Concrete.h"
#include"Game.h"
#include"Entity.h"
class ConcreteManager
{
public:
	void update(Entity Player);
	void render(Entity Player);
private:
	Concrete concreteArr[Game::ScreenSize / Game::gridSize][Game::ScreenSize / Game::gridSize];
};

