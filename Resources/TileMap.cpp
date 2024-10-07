#include "../Headers/TileMap.h"
#include "../Headers/TextureManager.h"

TileMap::TileMap(const int width, const int height, const int tileWidth, const int tileHeight) :
        width(width),
        height(height),
        tileWidth(tileWidth),
        tileHeight(tileHeight)
{
    map = new int*[width];
    for (int i = 0; i < width; i++)
    {
        map[i] = new int[height];
        memset(map[i], 0, height * sizeof(int));
    }

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = tileWidth;
    srcRect.h = tileHeight;

    destRect.x = 0;
    destRect.y = 0;
    destRect.w = tileWidth;
    destRect.h = tileHeight;
}

void TileMap::AddTexture(int mapIndex, SDL_Texture* texture)
{
    textures[mapIndex] = texture;
}

void TileMap::LoadMap(int** newMap)
{
    for (int i = 0; i < width; ++i)
    {
        memcpy(map[i], newMap[i], height * sizeof(int));
    }        
}

void TileMap::DrawMap()
{
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {            
            destRect.x = j * tileWidth;
            destRect.y = i * tileHeight;

            const auto tex = textures[map[i][j]];
            if(tex != nullptr)
            {
                TextureManager::Draw(tex, srcRect, destRect);                
            }
        }
    }
}
