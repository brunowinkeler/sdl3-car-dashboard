#pragma once

#include <SDL3/SDL.h>
#include <string>

namespace car::core
{
    class Renderer
    {
    public:
        static bool Init(const std::string &title, int width, int height);
        static void Clear();
        static void Present();
        static void Destroy();

        static SDL_Renderer *GetRenderer();
        static SDL_Window *GetWindow();

    private:
        static SDL_Window *window;
        static SDL_Renderer *renderer;
    };
}
