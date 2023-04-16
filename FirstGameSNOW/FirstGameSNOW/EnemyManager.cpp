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
	std::random_device rd; //generate seed
	std::mt19937 rng(rd()); //initialize seed
	std::uniform_int_distribution<int> dist(min, max); //used to define a uniform distribution of integers between the min and max values
	int tmpRand1 = dist(rng); //generates a random number
	int tmpRand2 = dist(rng);
	Entity.setLoc(tmpRand1 * Game::gridSize, tmpRand2 * Game::gridSize);
}