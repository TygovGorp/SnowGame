#pragma once
#include"SDL.h"
#include "Game.h"
#include<iostream>

using namespace std;

class KeyboardHandler
{
public:
	KeyboardHandler();
	~KeyboardHandler();

	void CheckInput();
private:
	SDL_Event event;
};

KeyboardHandler::KeyboardHandler()
{

}

KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::CheckInput()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			cout << "w" << endl;
			break;
		case SDLK_a:
			cout << "a" << endl;
			break;
		case SDLK_s:
			cout << "s" << endl;
			break;
		case SDLK_d:
			cout << "d" << endl;
			break;
		case SDLK_ESCAPE:
			cout << "ecs" << endl;
		default:
			break;
		}
	}
}