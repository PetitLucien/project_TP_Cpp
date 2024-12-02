#ifndef CAPTEUR_DISTANCE_HPP
#define CAPTEUR_DISTANCE_HPP

#include "mbed.h"

class CapteurDistance {
    private:
        AnalogIn capteur;
        PinName pin{A0};
    public:
        CapteurDistance(PinName pin);
        ~CapteurDistance()=default;
        void initCapteur(){AnalogIn capteur(this->pin);}
        uint16_t getDistance(){return uint16_t(capteur.read_u16()*0.01998425);};


};

#endif // CAPTEUR_DISTANCE_HPP