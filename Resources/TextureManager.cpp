#include "../Headers/TextureManager.h"

#include <SDL_image.h>
#include "../Headers/Game.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* loadedSurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::Renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    return texture;    
}
