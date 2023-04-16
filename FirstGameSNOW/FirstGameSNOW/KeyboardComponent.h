#pragma once
#include"SDL.h"
#include "Game.h"
#include<iostream>

using namespace std;

class KeyboardComponent
{
public:
	void CheckInput();
	static KeyboardComponent kh;
private:
	int X;
	int Y;
	SDL_Event event;
	void CheckBounds();
};
