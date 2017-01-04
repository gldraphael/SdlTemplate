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
    isFullscreen(fullscreen)
{
    quit = !init();
    if (!quit)
        printf("Initialized...\n");
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

    //Clear screen (white)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // draw the frame
    this->on_first_draw(renderer);

    // Render the frame
    SDL_RenderPresent(renderer);

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

		this->on_update();
		this->draw();

        // Wait for 100 ms
        SDL_Delay(100);
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

    //Initialize renderer color (rgba) to white
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

    return true;
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

void Application::on_first_draw(SDL_Renderer* renderer)
{
	printf("Drawing screen for the first time...\n");
}

void Application::on_update()
{
	
}

void Application::on_draw(SDL_Renderer* renderer)
{
	
}

void Application::draw()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	on_draw(renderer);
	SDL_RenderPresent(renderer);
}
