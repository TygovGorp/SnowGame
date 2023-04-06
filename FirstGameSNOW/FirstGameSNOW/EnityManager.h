#pragma once

#include "Game.h"

class EnityManager
{
public:

	void init();
	void update();
	void render();
	void clean();

protected:
	int Hp;
	int Dmg;
	int Speed;
};
