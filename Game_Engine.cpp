#include <memory>

#include "Headers/Game.h"
#include "SDL.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

std::shared_ptr<Game> game;

int main(int argc, char *argv[])
{
    const char* title = "SDL Study";

    game = std::make_shared<Game>();

    SDL_Init(SDL_INIT_EVERYTHING);
    game->Init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while (game->Running())
    {
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    game->Clean();

    return 0;
}