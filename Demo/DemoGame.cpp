#include "DemoGame.h"

void DemoGame::Init(const char* title, int width, int height, bool fullscreen)
{
    Game::Init(title, width, height, fullscreen);    

    GameObject* player = new GameObject("player");
    player->LoadTexture("Demo/Sprites/player-idle-1.png");

    gameObjects.push_back(player);
}
