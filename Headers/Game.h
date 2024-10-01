#pragma once
#include <list>

#include "GameObject.h"
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

protected:
    std::list<GameObject*> gameObjects; 

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;    
};
