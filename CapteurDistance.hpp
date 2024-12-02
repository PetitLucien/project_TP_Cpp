#ifndef CAPTEUR_DISTANCE_HPP
#define CAPTEUR_DISTANCE_HPP

#include "mbed.h"

class CapteurDistance {
public:
    CapteurDistance(PinName pin);
    ~CapteurDistance();

    uint16_t getDistance();

private:
    AnalogIn capteur;
};

#endif // CAPTEUR_DISTANCE_HPP