#include "dashboard/SpeedGauge.hpp"
#include "core/Renderer.hpp"
#include <SDL3/SDL.h>

using namespace car::dashboard;
using namespace car::core;

SpeedGauge::SpeedGauge(const model::CarState &state)
    : state(state)
{
}

void SpeedGauge::Render(int x, int y, int width, int height)
{
    SDL_Renderer *renderer = Renderer::GetRenderer();

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
}
