#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char *argv[])
{
    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create a fullscreen window
    SDL_Window *window = SDL_CreateWindow("Display PNG", 800, 600, SDL_WINDOW_FULLSCREEN);
    if (!window)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create the renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load the texture from the PNG file
    SDL_Texture *texture = IMG_LoadTexture(renderer, "assets/images/baby.png");
    if (!texture)
    {
        SDL_Log("Failed to load texture: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Get the dimensions of the texture
    int width = texture->w;
    int height = texture->h;

    // Define the position and size of the destination
    SDL_FRect destination = {0.0f, 0.0f, (float)width, (float)height};

    // Clear the screen
    SDL_RenderClear(renderer);

    // Render the texture at position (0,0)
    SDL_RenderTexture(renderer, texture, NULL, &destination);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Event loop to wait for a key press
    SDL_Event event;
    bool running = true;
    while (running)
    {
        // Wait indefinitely until an event occurs
        SDL_WaitEvent(&event);
        if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE)
        {
            running = false;
        }
    }

    // Free resources
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
