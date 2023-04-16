#pragma once
#include "Entity.h"
class BattleManager
{
public:
	bool checkBattle();
	void BattleFase(Entity* P, Entity* E);
	void Attack();
	void Heal();
	void Run();
};

