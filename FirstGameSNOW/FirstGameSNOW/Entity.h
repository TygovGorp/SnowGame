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
	int getHP();
	int getDMG();
	int getSPD();
	int EntityLocX;
	int EntityLocY;

private:
	int hp = 50;
	int dmg = 10;
	int spd = 5;
	int imgScale;
	SDL_Rect srcRect, destRect;
	SDL_Texture* playerTex;

};

