#include "Game.h"
#include "Managers.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;




bool Game::isRunning = false;

Game game;
extern Entity Player;
KeyboardComponent kh;
EnemyManager em;
BattleManager bm;
ConcreteManager cm;
Entity** AllEnemy;

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	/* for future implementation
	cout << "how many Enemys?\n";
	cin >> Game::EnemyCount;
	*/
	AllEnemy = em.init(Game::EnemyCount);

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

	Player.Build(100, 10, 5, 0, 0, 2, "assets/player.png");
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
	bm.checkBattle(AllEnemy, Player);
	kh.CheckInput();
	Player.Update();
	cm.PlaceConcrete(Player);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	Player.Render();
	cm.Render();
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}