#include "BattleManager.h"
#include <iostream>
#include"Game.h"
using namespace std;

void BattleManager::checkBattle(Entity** Enemies, Entity player)
{
	for (int i = 0; i < Game::EnemyCount; i++)
	{
		if (player.EntityLocX == Enemies[i]->EntityLocX
			&&
			player.EntityLocY == Enemies[i]->EntityLocY
			&&
			Enemies[i]->getHP() > 0 )
		{
			player.setBattle(1);
			Battle(player, Enemies[i]);
		}
		else
		{
			if (player.getBattle() == true)
			{
				player.setBattle(0);
			}
		}
	}

}

void BattleManager::Battle(Entity P, Entity* E)
{
	if (msgSent == false)
	{
		cout << "You encountert a enemy!\n What will you do?\n 1: Attack\n 2: Item\n 3: Run\n";
	}
	switch (Game::event.key.keysym.sym)
	{
	case SDLK_1:
		Attack(P, E);
		msgSent = true;
		break;
	case SDLK_2:
		Item(P, E);
		msgSent = true;
		break;
	case SDLK_3:
		Run(P, E);
		msgSent = true;
		break;
	default:
		msgSent = true;
		break;
	}
}

void BattleManager::Attack(Entity P, Entity* E)
{
	cout << "attack" << endl;
	E->setHP(P.getDMG());
	cout << E->getHP() << endl;
}

void BattleManager::Item(Entity P, Entity* E)
{
	cout << "Item" << endl;
}

void BattleManager::Run(Entity P, Entity* E)
{
	cout << "Run" << endl;
}