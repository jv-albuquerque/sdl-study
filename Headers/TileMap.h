#pragma once
#include <map>
#include <SDL_rect.h>
#include <SDL_render.h>

class TileMap
{
public:
    TileMap(int width, int height, int tileWidth = 32, int tileHeight = 32);
    ~TileMap();

    void AddTexture(int mapIndex, SDL_Texture* texture);
    
    void LoadMap(int** map);
    void DrawMap();

private:

    SDL_Rect srcRect;
    SDL_Rect destRect;

    int width;
    int height;
    int tileWidth;
    int tileHeight;

    std::map<int, SDL_Texture*> textures;

    int** map;
};
