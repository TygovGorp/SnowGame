#include"KeyboardComponent.h"
#include"Entity.h"
Entity Player;
KeyboardComponent keyb;
void KeyboardComponent::CheckInput()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		if (Player.getBattle() == 0)
		{
			if (Game::event.key.keysym.sym == SDLK_w)
			{
				//cout << "w" << endl;
				keyb.Y -= Game::gridSize;
			}
			if (Game::event.key.keysym.sym == SDLK_a)
			{
				//cout << "a" << endl;
				keyb.X -= Game::gridSize;
			}
			if (Game::event.key.keysym.sym == SDLK_s)
			{
				//cout << "s" << endl;
				keyb.Y += Game::gridSize;
			}
			if (Game::event.key.keysym.sym == SDLK_d)
			{
				//cout << "d" << endl;
				keyb.X += Game::gridSize;
			}
			if (Game::event.key.keysym.sym == SDLK_ESCAPE)
			{
				//cout << "ecs" << endl;
				Game::isRunning = false;
			}
			KeyboardComponent::CheckBounds();
		}

	}
}

void KeyboardComponent::CheckBounds()
{
	if (keyb.X > Game::ScreenSize - Game::gridSize)
	{
		keyb.X = 768 - Game::gridSize;
	}
	if (keyb.X < 0)
	{
		keyb.X = 0;
	}
	if (keyb.Y > Game::ScreenSize - Game::gridSize)
	{
		keyb.Y = Game::ScreenSize - Game::gridSize;
	}
	if (keyb.Y < 0)
	{
		keyb.Y = 0;
	}
	Player.setLoc(keyb.X, keyb.Y);
	//cout << Player.EntityLocX << "," << Player.EntityLocY << endl;			debug code
}