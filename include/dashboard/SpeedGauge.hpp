#pragma once

#include "model/CarState.hpp"

namespace car::dashboard
{
    class SpeedGauge
    {
    public:
        explicit SpeedGauge(const model::CarState &state);

        void Render(int x, int y, int width, int height);

    private:
        const model::CarState &state;
    };
}
