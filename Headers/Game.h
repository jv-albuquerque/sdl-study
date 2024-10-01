#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Game
{
public:
    Game();
    ~Game();

    void Init(const char* title, int posX, int posY, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    void Close();

    bool Running() const;

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;    
};
