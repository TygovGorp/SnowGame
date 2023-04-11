#include"KeyboardComponent.h"
#include"Entity.h"
#include<iostream>
Entity Player;
void KeyboardComponent::CheckInput()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			cout << "w" << endl;
			Y -= Game::gridSize;
			break;
		case SDLK_a:
			cout << "a" << endl;
			X -= Game::gridSize;
			break;
		case SDLK_s:
			cout << "s" << endl;
			Y += Game::gridSize;
			break;
		case SDLK_d:
			cout << "d" << endl;
			X += Game::gridSize;
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
	if (X > 800 - Game::gridSize)
	{
		X = 800 - Game::gridSize;
	}
	if (X < 0)
	{
		X = 0;
	}
	if (Y > 800 - Game::gridSize)
	{
		Y = 800 - Game::gridSize;
	}
	if (Y < 0)
	{
		Y = 0;
	}
	Player.setLoc(X, Y);
	//cout << Player.EntityLocX << "," << Player.EntityLocY << endl;			debug code
}