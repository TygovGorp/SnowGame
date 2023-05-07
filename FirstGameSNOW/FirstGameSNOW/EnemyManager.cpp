#include "EnemyManager.h"
#include "Game.h"
#include<iostream>
#include<random>

Entity** EnemyManager::init(int EnemyNum)
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

void EnemyManager::CheckDup(Entity** Entitys, int size)
{
	for (int i = 0; i < size; i++) {

		if (Entitys[i]->EntityLocX == 0 && Entitys[i]->EntityLocY == 0)
		{
			GenerateRandomInt(*Entitys[i]);
			CheckDup(Entitys, size);
		}

		for (int j = i + 1; j < size; j++) {

			if (Entitys[j]->EntityLocX == 0 && Entitys[j]->EntityLocY == 0)
			{
				GenerateRandomInt(*Entitys[i]);
				CheckDup(Entitys, size);
			}

			if (Entitys[i]->EntityLocX == Entitys[j]->EntityLocX 
				&&
				Entitys[i]->EntityLocY == Entitys[j]->EntityLocY) 
			{
				GenerateRandomInt(*Entitys[i]);
				CheckDup(Entitys, size);
			}

		}
	}
}

void EnemyManager::GenerateRandomInt(Entity& Entity)
{
	uint32_t x = std::random_device()();
	uint32_t y = std::random_device()();
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	y ^= y << 13;
	y ^= y >> 17;
	y ^= y << 5;
	int tmpRand1 = x % (Game::ScreenSize / Game::gridSize);
	int tmpRand2 = y % (Game::ScreenSize / Game::gridSize);
	Entity.setLoc(tmpRand1 * Game::gridSize, tmpRand2 * Game::gridSize);
}