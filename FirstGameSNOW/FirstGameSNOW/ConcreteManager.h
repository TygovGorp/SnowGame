#pragma once
#include"Concrete.h"
#include"Game.h"
#include"Entity.h"
class ConcreteManager
{
public:
	Concrete** init();
	void update(Entity Player, Concrete** AllConcrete);
	void render(Entity Player, Concrete** AllConcrete);
	void gameClear(Concrete** AllConcrete);
	bool concreteGameClear = false;
private:
	bool snowGone[Game::ScreenSize / Game::gridSize][Game::ScreenSize / Game::gridSize] = { false };
};

