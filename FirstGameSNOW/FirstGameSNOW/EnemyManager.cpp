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
		for (int j = i + 1; j < size; j++) {
			if (Entitys[i]->EntityLocX == Entitys[j]->EntityLocX 
				&&
				Entitys[i]->EntityLocY == Entitys[j]->EntityLocY) {
				std::cout << i << " and " << j << " are the in the same location" << std::endl;
				GenerateRandomInt(*Entitys[i]);
				CheckDup(Entitys, size);
			}

		}
	}
}

void EnemyManager::GenerateRandomInt(Entity& Entity)
{
	int min = 0;
	int max = Game::ScreenSize/Game::gridSize;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(min, max);
	int tmpRand1 = dist(rng);
	int tmpRand2 = dist(rng);
	Entity.setLoc(tmpRand1 * Game::gridSize, tmpRand2 * Game::gridSize);
}