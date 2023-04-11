#pragma once
#include"SDL.h"
class Entity
{
public:
	void Build(int h, int d, int s, int x, int y, int scale, const char* path);
	void Update();
	void Render();
	void setHP(int h);
	void setDMG(int d);
	void setSPD(int s);
	void setLoc(int x, int y);
	int EntityLocX;
	int EntityLocY;

private:
	int hp;
	int dmg;
	int spd;
	int imgScale;
	SDL_Rect srcRect, destRect;
	SDL_Texture* playerTex;

};

