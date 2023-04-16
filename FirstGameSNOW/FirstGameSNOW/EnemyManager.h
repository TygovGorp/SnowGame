#pragma once
#include "Entity.h"
#include <cstdlib>
class EnemyManager
{
public:
	Entity** init(int EnemyNum);
	void CheckDup(Entity** Entitys, int size);
	void GenerateRandomInt(Entity& Entity);
};

