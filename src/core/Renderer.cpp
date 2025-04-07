#include "core/Renderer.hpp"
#include <SDL3/SDL.h>

using namespace car::core;

SDL_Window *Renderer::window = nullptr;
SDL_Renderer *Renderer::renderer = nullptr;

bool Renderer::Init(const std::string &title, int width, int height)
{
    window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_RESIZABLE);
    if (!window)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Renderer::Clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    SDL_RenderClear(renderer);
}

void Renderer::Present()
{
    SDL_RenderPresent(renderer);
}

void Renderer::Destroy()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}

SDL_Renderer *Renderer::GetRenderer()
{
    return renderer;
}

SDL_Window *Renderer::GetWindow()
{
    return window;
}
