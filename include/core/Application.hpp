#pragma once

#include "model/CarState.hpp"
#include "core/InputHandler.hpp"
#include "dashboard/SpeedGauge.hpp"

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
        dashboard::SpeedGauge speedGauge;
    };
}
