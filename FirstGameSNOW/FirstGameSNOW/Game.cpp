#include "Game.h"
#include "Managers.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;




bool Game::isRunning = false;

Game game;
extern Entity Player;
KeyboardComponent kh;

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	Player.Build(30, 10, 5, 0, 0, 2, "assets/player.png");
}


void Game::handleEvents()
{

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	kh.CheckInput();
	Player.Update();
	/*
	destRect = Player.setLoc(2);
	//destRect = { Player.EntityLocX, Player.EntityLocY, 64, 64 };
	srcRect = { 0, 0, 32, 32 };
	*/
	
}

void Game::render()
{
	SDL_RenderClear(renderer);
	Player.Render();
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}