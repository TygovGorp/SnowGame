#include "Entity.h"
#include<string>
void Entity::Build(int h, int d, int s, int x, int y, int scale)
{
	hp = h;
	dmg = d;
	spd = s;
	EntityLocX = x;
	EntityLocY = y;

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

SDL_Rect Entity::setLoc(int scale)
{
	SDL_Rect  tmpRect = { EntityLocX, EntityLocY, 32 * scale, 32 * scale };
	return tmpRect;
}
/*
int Entity::getX(Entity e)
{
	return EntityLocX;
}
int Entity::getY(Entity e)
{
	return EntityLocY;
}
*/