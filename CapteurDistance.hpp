#ifndef CAPTEUR_DISTANCE_HPP
#define CAPTEUR_DISTANCE_HPP

#include "mbed.h"
#include <cstdint>

class CapteurDistance {
    private:
        AnalogIn capteur;
        uint16_t distance{0};
        PinName pin{A0};
        void setDistance(uint16_t value){this->distance=value;};
    public:
        CapteurDistance(PinName pin):capteur(pin){};
        ~CapteurDistance()=default;
        void initCapteur(){AnalogIn capteur(this->pin);}
        uint16_t getDistance(){return this->distance;};
        uint16_t readCapteur(){setDistance(uint16_t(capteur.read_u16()*0.01998425));return getDistance(); };


};
/*
 -distance uint16_t
        -setDistance()
        +CapteurDistance(Pinname)
        ~CapeteurDistance()
        +getDistance() uint16_t
        +readCapteur()
        */
#endif // CAPTEUR_DISTANCE_HPP