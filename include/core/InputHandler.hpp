#pragma once

#include <SDL3/SDL.h>
#include "model/CarState.hpp"

namespace car::core
{
    class InputHandler
    {
    public:
        explicit InputHandler(model::CarState &carState);

        void HandleEvent(const SDL_Event &event);

    private:
        model::CarState &state;

        void Accelerate();
        void Brake();
        void GearUp();
        void GearDown();
        void ToggleLeftSignal();
        void ToggleRightSignal();
        void SimulateTempIncrease();
        void SimulateFuelDecrease();
    };
}
