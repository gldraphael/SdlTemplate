#pragma once
#include "Application.h"
#include <string>

class MyApp : public Application
{
private:
    virtual void on_draw(SDL_Renderer* renderer);

public:
    MyApp();
};
