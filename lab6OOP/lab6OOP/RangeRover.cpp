#include "RangeRover.h"

RangeRover::RangeRover() {
    fuelCapacity = 40.0;
    fuelConsumption = 10.0;
    avgSpeedSunny = 110.0;
    avgSpeedRain = 90.0;
    avgSpeedSnow = 70.0;
}

double RangeRover::calculateTime(double circuitLength, Weather weather) {
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

const char* RangeRover::getName()
{
    return "RangeRover";
}