#pragma once
#include "Application.h"
#include <string>

class MyApp : public Application
{
private:
	virtual void on_init(SDL_Renderer* renderer);
	virtual void on_update();
    virtual void on_draw();
	
public:
    MyApp();
};
