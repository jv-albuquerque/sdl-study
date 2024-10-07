#include "../Headers//Game.h"
#include "../Headers/GameObject.h"


SDL_Renderer* Game::Renderer = nullptr;

Game::Game()
{
    
}

Game::~Game() 
{
    
}

void Game::Init(const char* title, const int width, const int height, const bool fullscreen)
{
    int flags = 0;    

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("SDL_Init Error: %s\n", SDL_GetError());
        isRunning = false;
        return;
    }

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    SDL_Log("Subsystem initialized");
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (window)
    {
        SDL_Log("Window created");
    }

    Renderer = SDL_CreateRenderer(window, -1, 0);
    if (Renderer)
    {
        SDL_SetRenderDrawColor(Renderer, 55, 76, 117, 255);
        SDL_Log("Renderer created");
    }

    isRunning = true;
}

void Game::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::Update()
{
    for (auto go : gameObjects)
    {
        if(go == NULL)
        {
            gameObjects.remove(go);
        }
        else
        {
            go->Update();
        }
    }
}

void Game::Render()
{
    SDL_RenderClear(Renderer);    
    
    for (auto go : gameObjects)
    {
        go->Render();
    }
    
    SDL_RenderPresent(Renderer);
}

void Game::Clean()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    SDL_Log("Game Cleaned");
}

void Game::Close()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(window);
    Renderer = nullptr;
    window = nullptr;
}

bool Game::Running() const
{
    return isRunning;
}
