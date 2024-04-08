#include "Volvo.h"

Volvo::Volvo() {
    fuelCapacity = 45.0;
    fuelConsumption = 11.0;
    avgSpeedSunny = 115.0;
    avgSpeedRain = 90.0;
    avgSpeedSnow = 75.0;
}

double Volvo::calculateTime(double circuitLength, Weather weather) {
    double speed;
    if (weather == Weather::Rain) {
        speed = avgSpeedRain;
    }
    else if (weather == Weather::Sunny) {
        speed = avgSpeedSunny;
    }
    else {
        speed = avgSpeedSnow;
    }

    double time = circuitLength / speed * 60 * 60;
    double fuelConsumed = fuelConsumption * circuitLength / 100;
    if (fuelConsumed > fuelCapacity) {
        return -1.0;
    }


    return time;
}

const char* Volvo::getName()
{
    return "Volvo";
}