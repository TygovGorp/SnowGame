#pragma once
#include"SDL.h"
#include "Game.h"
#include<iostream>

using namespace std;

class KeyboardComponent
{
public:
	void CheckInput();
	int playerX;
	int playerY;
private:
	SDL_Event event;
	void CheckBounds();
};
