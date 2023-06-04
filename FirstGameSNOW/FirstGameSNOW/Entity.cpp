#include "Entity.h"
#include"TextureManager.h"
void Entity::Build(int h, int d, int s, int x, int y, int scale, const char* path)
{
	hp = h;
	dmg = d;
	spd = s;
	EntityLocX = x;
	EntityLocY = y;
	imgScale = scale;
	playerTex = TextureManager::LoadTexture(path);
}

void Entity::Update()
{
	destRect = { EntityLocX, EntityLocY, Game::gridSize, Game::gridSize };
	srcRect = { 0, 0, 32, 32 };
}

void Entity::Render()
{
	TextureManager::Draw(playerTex, srcRect, destRect);
}

void Entity::setHP(int h)
{
	if ((hp -= h) > 0)
	{
		dmg -= h;
	}
	else
	{
		std::cout << "Enemy has gone to the after life" << std::endl;
	}
}

void Entity::setDMG(int d)
{
	if ((dmg -= d) > 0)
	{
		dmg -= d;
	}
	else
	{
		dmg = 1;
	}
	
}

void Entity::setSPD(int s)
{
	if ((spd -= s) > 0)
	{
		spd -= s;
	}
	else
	{
		spd = 1;
	}
}

void Entity::setLoc(int x, int y)
{
	EntityLocX = x;
	EntityLocY = y;
}

void Entity::setBattle(int yn) //y = 1 n = 0 
{
	switch (yn)
	{
	case 1:
		isInBattle = true;
		break;
	case 2:
		isInBattle = false;
		break;
	default:
		break;
	}

}

int Entity::getHP()
{
	return hp;
}

int Entity::getDMG()
{
	return dmg;
}

int Entity::getSPD()
{
	return spd;
}

bool Entity::getBattle()
{
	return isInBattle;
}

