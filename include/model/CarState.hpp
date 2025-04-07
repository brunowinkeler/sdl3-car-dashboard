#pragma once

namespace car::model
{
    enum class Gear
    {
        Reverse,
        Neutral,
        First,
        Second,
        Third,
        Fourth,
        Fifth
    };

    struct CarState
    {
        float speed = 0.0f;        // km/h
        float rpm = 0.0f;          // engine RPM
        float temperature = 90.0f; // °C
        float fuelLevel = 100.0f;  // %
        Gear gear = Gear::Neutral;
        bool leftSignal = false;
        bool rightSignal = false;
        bool warningActive = false;
        float odometer = 0.0f; // km
    };
}
