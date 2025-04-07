#pragma once

#include "model/CarState.hpp"
#include "core/InputHandler.hpp"
#include "dashboard/SpeedGauge.hpp"
#include <SDL3_ttf/SDL_ttf.h>
#include <memory>

namespace car::core
{
    class Application
    {
    public:
        Application();
        ~Application();

        int Run();

    private:
        bool Init();
        void HandleEvents();
        void Update();
        void Render();
        void CleanUp();

        bool isRunning;

        model::CarState carState;
        InputHandler inputHandler;
        std::unique_ptr<dashboard::SpeedGauge> pSpeedGauge;
        TTF_Font *font = nullptr;
    };
}
