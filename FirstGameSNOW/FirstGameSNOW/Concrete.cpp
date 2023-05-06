#include "Concrete.h"
#include "Game.h"
#include<iostream>
#include<random>

Entity** Concrete::init(int EnemyNum)
{
	Entity** Enemies = new Entity * [EnemyNum];
	for (int i = 0; i < EnemyNum; i++)
	{
		Enemies[i] = new Entity();
		GenerateRandomInt(*Enemies[i]);
	}
	CheckDup(Enemies, EnemyNum);
	return Enemies;
}

void Concrete::CheckDup()
{
}