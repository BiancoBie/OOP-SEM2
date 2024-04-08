#include "Seat.h"

Seat::Seat() {
    fuelCapacity = 30.0;
    fuelConsumption = 6.0;
    avgSpeedSunny = 90.0;
    avgSpeedRain = 70.0;
    avgSpeedSnow = 50.0;
}

double Seat::calculateTime(double circuitLength, Weather weather) {
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

const char* Seat::getName()
{
    return "Seat";
}