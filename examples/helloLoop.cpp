#include <SDL3/SDL.h>

int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_VIDEO) != true)
    {
        SDL_Log("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL3 Basic Example", 800, 600, SDL_WINDOW_FULLSCREEN);
    if (!window)
    {
        SDL_Log("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
    {
        SDL_Log("Erro ao criar renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 30, 144, 255, 255); // Azul DodgerBlue
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_FRect rect = {300, 200, 200, 150}; // x, y, largura, altura
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
