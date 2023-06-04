#include "GameClear.h"
#include"TextureManager.h"

void GameClear::init()
{
	GameClearTex = TextureManager::LoadTexture("assets/GameClear.png");
}

void GameClear::update()
{
	destRect = { 0, 0, Game::ScreenSize, Game::ScreenSize };
	srcRect = { 0, 0, Game::ScreenSize, Game::ScreenSize };
}

void GameClear::render()
{
	TextureManager::Draw(GameClearTex, srcRect, destRect);
}