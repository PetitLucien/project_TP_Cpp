#ifndef PIFOMETRE_HPP
#define PIFOMETRE_HPP

#include "Ecran.hpp"
#include "CapteurDistance.hpp"
#include "Keypad.hpp"
#include <cstdint>

#define MARGE 10

class Pifometre {
public:
    Pifometre(); // Constructor
    ~Pifometre(); // Destructor

    // You can add methods here later
    void run(); // Potential main execution method
    void DistanceVSguess(uint16_t distance, int16_t guess);

private:
    Ecran screen;
    CapteurDistance distanceSensor;
    Keypad clavier;
    bool guessOk{0};
    void setguessOk(){this->guessOk=1;};
    void resetguessOk(){this->guessOk=0;};
    const bool getguessOk(){return this->guessOk;};
};

#endif // PIFOMETRE_HPP