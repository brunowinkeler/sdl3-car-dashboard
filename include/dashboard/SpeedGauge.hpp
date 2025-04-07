#pragma once

#include "model/CarState.hpp"
#include <SDL3_ttf/SDL_ttf.h>

namespace car::dashboard
{
    class SpeedGauge
    {
    public:
        explicit SpeedGauge(const model::CarState &state, TTF_Font *font);

        void Render(int x, int y, int width, int height);

    private:
        const model::CarState &state;
        TTF_Font *font;
    };
}
