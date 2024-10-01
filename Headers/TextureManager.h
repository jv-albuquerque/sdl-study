#pragma once
#include <SDL_render.h>

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
};
