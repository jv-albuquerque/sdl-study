#include <memory>

#include "Headers/Game.h"
#include "SDL.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define FPS_CAP 60

std::shared_ptr<Game> game;

int main(int argc, char *argv[])
{
    constexpr int frameMinTime = 1000 / FPS_CAP;
    Uint32 startTicks;
    int frameTime;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    const char* title = "SDL Study";
    game = std::make_shared<Game>();
    game->Init(title, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while (game->Running())
    {
        startTicks = SDL_GetTicks();
        
        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - startTicks;
        if (frameTime < frameMinTime)
        {
            SDL_Delay(frameMinTime - frameTime);
        }
    }

    game->Clean();

    return 0;
}