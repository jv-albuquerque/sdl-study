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

    //TODO: DELETE THIS
    virtual void TempRender() { }
    
    static SDL_Renderer* Renderer;

protected:
    std::list<GameObject*> gameObjects;
    
    bool isRunning;
    SDL_Window* window;    
};
