#include <utility>

#include "../Headers/GameObject.h"

#include "../Headers/Game.h"
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

void GameObject::LoadTexture(const char* texturePath)
{
    texture = TextureManager::LoadTexture(texturePath);
}

void GameObject::Update()
{
}

void GameObject::Render()
{
    TextureManager::Draw(texture, srcRect, destRect);
}
