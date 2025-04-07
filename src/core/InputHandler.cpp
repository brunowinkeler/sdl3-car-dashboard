#include "core/InputHandler.hpp"

using namespace car::core;
using namespace car::model;

InputHandler::InputHandler(CarState &carState)
    : state(carState), accelerateHeld(false)
{
}

void InputHandler::HandleEvent(const SDL_Event &event)
{
    if (event.type == SDL_EVENT_KEY_DOWN)
    {
        SDL_Keycode key = event.key.key;

        if (key == SDLK_UP)
        {
            accelerateHeld = true;
        }

        switch (key)
        {
        case SDLK_LEFT:
            ToggleLeftSignal();
            break;
        case SDLK_RIGHT:
            ToggleRightSignal();
            break;
        case SDLK_A:
            GearDown();
            break;
        case SDLK_D:
            GearUp();
            break;
        case SDLK_W:
            SimulateTempIncrease();
            break;
        case SDLK_S:
            SimulateFuelDecrease();
            break;
        case SDLK_DOWN:
            Brake();
            break;
        default:
            break;
        }
    }
    else if (event.type == SDL_EVENT_KEY_UP)
    {
        if (event.key.key == SDLK_UP)
        {
            accelerateHeld = false;
        }
    }
}

void InputHandler::Accelerate()
{
    if (state.speed < 240.0f)
    {
        state.speed += 1.0f;
        state.rpm += 100.0f;
        state.odometer += 0.01f;
    }
}

void InputHandler::Brake()
{
    if (state.speed > 0.0f)
    {
        state.speed -= 4.0f;
        state.rpm -= 150.0f;
    }

    if (state.speed < 0.1f)
    {
        state.speed = 0.0f;
        state.rpm = 800.0f;
    }
}

void InputHandler::GearUp()
{
    if (state.gear != Gear::Fifth)
    {
        state.gear = static_cast<Gear>(static_cast<int>(state.gear) + 1);
    }
}

void InputHandler::GearDown()
{
    if (state.gear != Gear::Reverse)
    {
        state.gear = static_cast<Gear>(static_cast<int>(state.gear) - 1);
    }
}

void InputHandler::ToggleLeftSignal()
{
    state.leftSignal = !state.leftSignal;
}

void InputHandler::ToggleRightSignal()
{
    state.rightSignal = !state.rightSignal;
}

void InputHandler::SimulateTempIncrease()
{
    if (state.temperature < 120.0f)
    {
        state.temperature += 1.0f;
    }
}

void InputHandler::SimulateFuelDecrease()
{
    if (state.fuelLevel > 0.0f)
    {
        state.fuelLevel -= 0.5f;
    }
}

void InputHandler::Update()
{
    if (accelerateHeld)
    {
        Accelerate();
    }
    else
    {
        if (state.speed > 0.0f)
        {
            state.speed -= 0.5f;
            state.rpm -= 50.0f;

            if (state.speed < 0.0f)
            {
                state.speed = 0.0f;
                state.rpm = 800.0f;
            }
        }
    }
}