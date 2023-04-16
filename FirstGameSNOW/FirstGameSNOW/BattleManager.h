#pragma once
#include "Entity.h"
class BattleManager
{
public:
	void checkBattle(Entity** Enemies, Entity player);
	void Battle(Entity P, Entity* E);
	void Attack(Entity P, Entity* E);
	void Item(Entity P, Entity* E);
	void Run(Entity P, Entity* E);
};

