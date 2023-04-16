#include"KeyboardComponent.h"
#include"Entity.h"
Entity Player;
KeyboardComponent keyb;
void KeyboardComponent::CheckInput()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			cout << "w" << endl;
			keyb.Y -= Game::gridSize;
			break;
		case SDLK_a:
			cout << "a" << endl;
			keyb.X -= Game::gridSize;
			break;
		case SDLK_s:
			cout << "s" << endl;
			keyb.Y += Game::gridSize;
			break;
		case SDLK_d:
			cout << "d" << endl;
			keyb.X += Game::gridSize;
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