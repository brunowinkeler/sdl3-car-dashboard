#include "core/Application.hpp"
#include "core/Renderer.hpp"
#include <SDL3/SDL.h>

using namespace car::core;

Application::Application()
    : isRunning(false),
      inputHandler(carState),
      speedGauge(carState)
{
}

Application::~Application()
{
    CleanUp();
}

int Application::Run()
{
    if (!Init())
    {
        return -1;
    }

    while (isRunning)
    {
        HandleEvents();
        Update();
        Render();
    }

    return 0;
}

bool Application::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != true)
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    if (!Renderer::Init("Car Dashboard", 800, 480))
    {
        return false;
    }

    isRunning = true;
    return true;
}

void Application::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            isRunning = false;
        }

        inputHandler.HandleEvent(event);
    }
}

void Application::Update()
{
}

void Application::Render()
{
    Renderer::Clear();

    speedGauge.Render(100, 100, 600, 30); // exemplo

    Renderer::Present();
}

void Application::CleanUp()
{
    Renderer::Destroy();
    SDL_Quit();
}
