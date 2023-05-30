#include "BattleManager.h"
#include <iostream>
#include"Game.h"
#include"TextureManager.h"
using namespace std;

void BattleManager::init()
{
	TextTex = TextureManager::LoadTexture("assets/BattleUI.png");
	destRect = { 0, 0, Game::ScreenSize, Game::ScreenSize };
	srcRect = { 0, 0, Game::ScreenSize, Game::ScreenSize };
}

void BattleManager::update(Entity** Enemies, Entity player)
{
	for (int i = 0; i < Game::EnemyCount; i++)
	{
		if (player.EntityLocX == Enemies[i]->EntityLocX
			&&
			player.EntityLocY == Enemies[i]->EntityLocY
			&&
			Enemies[i]->getHP() > 0 )
		{
			//player.setBattle(1);
			renderMsg = true;
			enemyNum = i;
			Battle(player, Enemies[i]);
		}
		else
		{
			if (enemyNum == i)
			{
				player.setBattle(0);
				renderMsg = false;
			}
		}
	}
}

void BattleManager::render()
{
	TextureManager::Draw(TextTex, srcRect, destRect);
}

void BattleManager::Battle(Entity P, Entity* E)
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_1:
			Attack(P, E);
			break;
		case SDLK_2:
			Item(P, E);
			break;
		case SDLK_w:
		case SDLK_a:
		case SDLK_s:
		case SDLK_d:
			renderMsg = false;
			break;
		default:
			break;
		}
	}
}

void BattleManager::Attack(Entity P, Entity* E)
{
	cout << "attack" << endl;
	E->setHP(P.getDMG());
	cout << E->getHP() << endl;
	if (E->getHP() <= 0)
	{
		renderMsg = false;
	}
	
}

void BattleManager::Item(Entity P, Entity* E)
{
	cout << "Item" << endl;
	
}