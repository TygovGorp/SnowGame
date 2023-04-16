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

			cout << "fight" << endl;
			Battle(player, Enemies[i]);
		}
	}

}

void BattleManager::Battle(Entity P, Entity* E)
{
	
	cout << "You encountert a enemy!\n What will you do?\n 1: Attack\n 2: Item\n 3: Run\n";
	int ans;
	cin >> ans;
	switch (ans)
	{
	case 1:
		Attack(P, E);
		break;
	case 2:
		Item(P, E);
		break;
	case 3:
		Run(P, E);
		break;
	default:
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