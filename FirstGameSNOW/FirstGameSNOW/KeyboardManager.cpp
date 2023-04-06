#include"KeyboardComponent.h"
#include<iostream>
using namespace std;

void KeyboardComponent::CheckInput()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			cout << "w" << endl;
			playerY -= Game::gridsize;
			break;
		case SDLK_a:
			cout << "a" << endl;
			playerX -= Game::gridsize;
			break;
		case SDLK_s:
			cout << "s" << endl;
			playerY += Game::gridsize;
			break;
		case SDLK_d:
			cout << "d" << endl;
			playerX += Game::gridsize;
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
	if (playerX > 800 - Game::gridsize)
	{
		playerX = 800 - Game::gridsize;
	}
	if (playerX < 0)
	{
		playerX = 0;
	}
	if (playerY > 800 - Game::gridsize)
	{
		playerY = 800 - Game::gridsize;
	}
	if (playerY < 0)
	{
		playerY = 0;
	}

}