#include <utility>

#include "../Headers/GameObject.h"
#include "../Headers/TextureManager.h"

GameObject::GameObject(std::string name, const int x, const int y, const int width, const int height) :
    name(std::move(name)),
    posX(x),
    posY(y)
{
    //TODO: Transform
    srcRect.x = x;
    srcRect.y = y;
    srcRect.h = height;
    srcRect.w = width;
    
    destRect.x = x;
    destRect.y = y;
    destRect.h = height*2;
    destRect.w = width*2;
}

GameObject::~GameObject()
{
}

void GameObject::LoadTexture(const char* texturePath, SDL_Renderer* renderer)
{
    texture = TextureManager::LoadTexture("Demo/Sprites/player-idle-1.png", renderer);
}

void GameObject::Update()
{
}

void GameObject::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
