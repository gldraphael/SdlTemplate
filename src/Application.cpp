#include "Application.h"
#include <cstdio>

Application::Application()
    : Application("Untitled Window")
{ }

Application::Application(std::string title)
  : Application(title, 640, 480, false)
{ }

Application::Application(std::string title, unsigned int width, unsigned int height)
  : Application(title, width, height, false)
{ }

Application::Application(std::string title, unsigned int width, unsigned int height, bool fullscreen)
	: window(NULL),
    renderer(NULL),
    title(title),
    windowWidth(640),
    windowHeight(480),
    isFullscreen(fullscreen),
	backgroundColor({ 0xFF, 0xFF, 0xFF, 0xFF }),
	quit(false)
{
    
}


Application::~Application()
{
    printf("Closing...\n");
    close();
}


void Application::Run()
{
    //Event handler
    SDL_Event e;

	// Initialize the app
	quit = !init();
    if (quit)
        printf("Initialization failed\n");

    printf("Entering application loop...\n");

    //While application is running
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
                quit = true;

            // Quit if the user presses ESC when the window is fullscreen
            if (isFullscreen && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
            }
        }

		// Update state
		this->on_update();

		// Perform rendering
		this->draw();

        // Wait for 10 ms
        SDL_Delay(10);
    }
}


bool Application::init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
        printf("Warning: Linear texture filtering not enabled!");
    }

    //Create the window
    int flags = SDL_WINDOW_SHOWN;
    if (isFullscreen)
        flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, flags);
    if (window == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    //Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

	// Windows are ready, trigger the on_init event
	this->on_init();

    //Initialize renderer color (rgba) to background color
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);

    return true;
}

void Application::on_init()
{
    printf("Initialization complete...\n");
}

void Application::close()
{
    // Free resources & zero pointers
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    // Quit
    SDL_Quit();
}

void Application::on_update()
{
	
}

void Application::on_draw(SDL_Renderer* renderer)
{
	
}

void Application::draw()
{
	//Clear screen using the background color
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderClear(renderer);

	// Trigger the on_draw event
	on_draw(renderer);

	// Update the screen
	SDL_RenderPresent(renderer);
}

void Application::set_background_color(SDL_Color color)
{
	this->backgroundColor = color;
}
