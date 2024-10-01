#pragma once
#include "SDL.h"

class Game
{
public:
    Game();
    ~Game();

    void Init(const char* title, int width, int height, bool fullscreen);
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
