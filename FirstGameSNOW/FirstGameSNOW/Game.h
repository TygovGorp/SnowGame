#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>


class Game
{
public:
	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static bool isRunning;
	static const int gridSize = 64;
	static const int ScreenSize = 768;
	static const int EnemyCount = 10;
private:

	SDL_Window* window;
};