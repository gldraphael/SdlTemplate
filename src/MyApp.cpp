#include "MyApp.h"
#include <cstdio>

MyApp::MyApp()
	: Application("My App")
{
	
}

// Declare state variables
// The position & dimension of the rectangle
SDL_Rect rect = { 106, 190, 50, 50 };
// The rate at which the rectangle moves along the x axis
// +ve value moves right; -ve value moves left
int dx = 2;

void MyApp::on_init()
{
	Application::on_init();

	// TODO: Add initialization logic here

	// Set the background color to black
	set_background_color({ 0x00, 0x00, 0x00, 0xFF });
	// Any other initialization code will go here
}

void MyApp::on_update()
{
	Application::on_update();

	// TODO: Add update logic here

	// If the rectangle is touching the left edge
	// And is moving towards the left
	// Change its direction
	if(rect.x <= 0 && dx < 0)
	{
		dx = -dx;
	}

	// If the rectangle is touching the right edge
	// And is moving towards the right
	// Change its direction
	if(rect.x + rect.w >= get_window_width() && dx > 0)
	{
		dx = -dx;
	}

	// Move the rectangle
	rect.x += dx;

}

void MyApp::on_draw(SDL_Renderer* renderer)
{
	Application::on_draw(renderer);

	// TODO: Add drawing logic here

	// Set the draw color to #E03C42 (a shade of red)
	SDL_SetRenderDrawColor(renderer, 0xE0, 0x3C, 0x42, 0xFF);
	// Draw a filled rectangle
    SDL_RenderFillRect(renderer, &rect);

}
