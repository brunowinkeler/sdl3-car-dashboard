#include "dashboard/SpeedGauge.hpp"
#include "core/Renderer.hpp"
#include <SDL3/SDL.h>
#include <string>

using namespace car::dashboard;
using namespace car::core;

SpeedGauge::SpeedGauge(const model::CarState &state, TTF_Font *font)
    : state(state), font(font)
{
}

void SpeedGauge::Render(int x, int y, int width, int height)
{
    // Render text (speed value)
    SDL_Renderer *renderer = Renderer::GetRenderer();
    std::string speedText = std::to_string(static_cast<int>(state.speed)) + " km/h";

    // Draw border
    SDL_FRect border = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    SDL_RenderRect(renderer, &border);

    // Calculate bar width based on speed
    float speedRatio = state.speed / 240.0f;
    int fillWidth = static_cast<int>(speedRatio * width);

    // Draw fill bar
    SDL_FRect fill = {x, y, fillWidth, height};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(renderer, &fill);

    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, speedText.c_str(), speedText.length(), white);
    if (surface)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture)
        {
            float textW = 0, textH = 0;
            SDL_GetTextureSize(texture, &textW, &textH);
            SDL_FRect dest = {x + width + 10, y + (height / 2) - (textH / 2), textW, textH};
            SDL_RenderTexture(renderer, texture, NULL, &dest);
            SDL_DestroyTexture(texture);
        }
        SDL_DestroySurface(surface);
    }
}
