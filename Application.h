#pragma once
#include <SDL2/SDL.h>
#include <string>

class Application
{
private:
    // Main loop flag
    bool quit;

    // The window
    SDL_Window* window;

    // The window renderer
    SDL_Renderer* renderer;

	// The background color
	SDL_Color backgroundColor;

    // Window properties
    std::string title;
    unsigned int windowWidth;
    unsigned int windowHeight;
    bool isFullscreen;

    bool init();
    void close();
	void draw();

protected:

	// Event called after initialized
    virtual void on_init();

	// Event called when before drawing the screen in the loop
    virtual void on_update();

	// Event called when drawing the screen in the loop
    virtual void on_draw(SDL_Renderer* renderer);


	void set_background_color(SDL_Color color);
	
	unsigned int get_window_height() 
	{
		return windowHeight;
	}

	unsigned int get_window_width() 
	{
		return windowWidth;
	}

	bool is_fullscreen() 
	{
		return isFullscreen;
	}

public:
    Application();
    Application(std::string title);
	Application(std::string title, unsigned int width, unsigned int height);
    Application(std::string title, unsigned int width, unsigned int height, bool fullscreen);
    ~Application();

    void Run();
};
