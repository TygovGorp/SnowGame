#pragma once
#include"SDL.h"
#include "Game.h"
#include<iostream>

using namespace std;

class KeyboardComponent
{
public:
	KeyboardComponent();
	~KeyboardComponent();

	void CheckInput();
	int playerX;
	int playerY;
private:
	SDL_Event event;
	void CheckBounds();
};

KeyboardComponent::KeyboardComponent()
{

}

KeyboardComponent::~KeyboardComponent()
{
}

void KeyboardComponent::CheckInput()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			cout << "w" << endl;
			playerY -= 64;
			break;
		case SDLK_a:
			cout << "a" << endl;
			playerX -= 64;
			break;
		case SDLK_s:
			cout << "s" << endl;
			playerY += 64;
			break;
		case SDLK_d:
			cout << "d" << endl;
			playerX += 64;
			break;
		case SDLK_ESCAPE:
			cout << "ecs" << endl;
			Game::isRunning = false;
		default:
			break;
		}
		KeyboardComponent::CheckBounds();
	}
}

void KeyboardComponent::CheckBounds()
{
	if (playerX > 800 - 64)
	{
		playerX = 800 - 64;
	}
	if (playerX < 0)
	{
		playerX = 0;
	}
	if (playerY > 800 - 64)
	{
		playerY = 800 - 64;
	}
	if (playerY < 0)
	{
		playerY = 0;
	}

}