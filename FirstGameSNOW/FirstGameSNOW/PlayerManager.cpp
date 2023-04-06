#include"PlayerManager.h"
#include"KeyboardComponent.h"
#include"TextureManager.h"
KeyboardComponent KeyB;


void PlayerManager::init()
{
	playerTex = TextureManager::LoadTexture("assets/player.png");
}

void PlayerManager::update()
{
	destRect.x = KeyB.playerX;
	destRect.y = KeyB.playerY;
	destRect.w = Game::gridsize;
	destRect.h = Game::gridsize;

	srcRect = { 0, 0, 32, 32 };
}

void PlayerManager::render()
{
	TextureManager::Draw(playerTex, srcRect, destRect);
}

void PlayerManager::clean() 
{

}
