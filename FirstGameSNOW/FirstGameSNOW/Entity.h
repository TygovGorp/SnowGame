#pragma once
class Entity
{
public:
	void Build(int h, int d, int s, int x, int y, int scale);
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

};

