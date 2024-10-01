#pragma once
#include <SDL_render.h>
#include <string>

//TODO: Create a Transform component
//TODO: Create a Sprite Render
class GameObject
{
public:
    GameObject(std::string name, int x = 0, int y = 0, int width = 32, int height = 32);
    ~GameObject();

    //TODO: Sprite render
    void LoadTexture(const char* texturePath, SDL_Renderer* renderer);

    void Update();
    void Render(SDL_Renderer* renderer);

private:
    std::string name;

    //TODO: Transform
    int posX;
    int posY;

    //TODO: Sprite Render
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
};
