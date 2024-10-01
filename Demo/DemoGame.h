#pragma once
#include "../Headers/Game.h"

class DemoGame : public Game
{
public:
    DemoGame() : Game() { }
    ~DemoGame() { }
    void Init(const char* title, int width, int height, bool fullscreen);
};
