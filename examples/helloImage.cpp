#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

void getDisplayResolution(int &width, int &height)
{
    int numDisplays = 0;
    SDL_DisplayID *displays = SDL_GetDisplays(&numDisplays);
    if (!displays || numDisplays <= 0)
    {
        SDL_Log("Failed to get display list: %s", SDL_GetError());
        return;
    }

    SDL_DisplayID display = displays[0]; // Using the first display

    SDL_Rect bounds;
    if (SDL_GetDisplayBounds(display, &bounds) != true)
    {
        SDL_Log("SDL_GetDisplayBounds Error: %s", SDL_GetError());
        SDL_free(displays);
        return;
    }
    width = bounds.w;
    height = bounds.h;
    SDL_free(displays);
}

int main(int argc, char *argv[])
{
    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    int widthScreen = 0, heightScreen = 0;
    getDisplayResolution(widthScreen, heightScreen);
    SDL_Log("Display resolution after getDisplayResolution: %dx%d", widthScreen, heightScreen);

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
    SDL_Texture *texture = IMG_LoadTexture(renderer, "assets/images/lady.jpg");
    if (!texture)
    {
        SDL_Log("Failed to load texture: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Get the dimensions of the texture
    int widthImage = texture->w;
    int heightImage = texture->h;

    float widthScaled = (float)(widthImage * heightScreen) / heightImage;

    int posX = (widthScreen - widthScaled) / 2;
    int posY = 0;

    // Define the position and size of the destination
    SDL_FRect destination = {(float)posX, (float)posY, widthScaled, (float)heightScreen};

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
