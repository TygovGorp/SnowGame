#include "BattleManager.h"
#include <iostream>
#include"Game.h"


void BattleManager::checkBattle(Entity** Enemies, Entity player)
{
	for (int i = 0; i < Game::EnemyCount; i++)
	{
		if (player.EntityLocX == Enemies[i]->EntityLocX
			&&
			player.EntityLocY == Enemies[i]->EntityLocY)
		{
			std::cout << "fight" << std::endl;
			//Battle(player, Enemies[i]);
		}
	}

}

void BattleManager::Battle(Entity P, Entity* E)
{
	
}

void BattleManager::Attack()
{

}

void BattleManager::Heal()
{

}

void BattleManager::Run()
{

}