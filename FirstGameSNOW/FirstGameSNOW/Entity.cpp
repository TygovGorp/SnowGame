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
	hp = h;
}

void Entity::setDMG(int d)
{
	dmg = d;
}

void Entity::setSPD(int s)
{
	spd = s;
}

void Entity::setLoc(int x, int y)
{
	EntityLocX = x;
	EntityLocY = y;
}