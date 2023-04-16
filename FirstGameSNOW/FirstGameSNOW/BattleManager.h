#pragma once
#include "Entity.h"
class BattleManager
{
public:
	void checkBattle(Entity** Enemies, Entity player);
	void Battle(Entity P, Entity* E);
	void Attack();
	void Heal();
	void Run();
};

