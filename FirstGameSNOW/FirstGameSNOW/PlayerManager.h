#pragma once
#include "EntityManager.h"

class PlayerManager : public EntityManager
{
public:
	void init();
	void update();
	void render();
	void clean();

private:

};
