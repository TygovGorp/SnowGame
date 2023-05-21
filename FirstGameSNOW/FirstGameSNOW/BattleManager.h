#pragma once
#include "Entity.h"
class BattleManager
{
public:
	void init();
	void update(Entity** Enemies, Entity player);
	void render();
	void Battle(Entity P, Entity* E);
	void Attack(Entity P, Entity* E);
	void Item(Entity P, Entity* E);
	bool renderMsg = false;
private:
	bool msgSent = false;
	bool just_walked_in = true;
	SDL_Rect srcRect, destRect;
	SDL_Texture* TextTex;
};

