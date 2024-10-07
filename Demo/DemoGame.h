#pragma once
#include "../Headers/Game.h"

class DemoGame : public Game
{
public:
    DemoGame() = default;
    ~DemoGame() = default;
    
    void Init(const char* title, int width, int height, bool fullscreen);

    void TempRender() override;
};
