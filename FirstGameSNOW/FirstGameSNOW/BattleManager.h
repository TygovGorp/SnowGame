#pragma once
#include "Entity.h"
class BattleManager
{
public:
	void init();
	void update(Entity** Enemies, Entity player);
	void render();
	void gameClear(Entity** Enemies);
	void Battle(Entity P, Entity* E);
	void Attack(Entity P, Entity* E);
	void Item(Entity P, Entity* E);
	bool renderMsg = false;
	bool battleGameClear = false;
private:
	int enemyNum = NULL;
	SDL_Rect srcRect, destRect;
	SDL_Texture* TextTex;
};

