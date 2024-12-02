#ifndef PIFOMETRE_HPP
#define PIFOMETRE_HPP

#include "Ecran.hpp"
#include "CapteurDistance.hpp"
#include "Keypad.hpp"

class Pifometre {
public:
    Pifometre(); // Constructor
    ~Pifometre(); // Destructor

    // You can add methods here later
    void run(); // Potential main execution method

private:
    Ecran screen;
    CapteurDistance distanceSensor;
    Keypad inputDevice;
};

#endif // PIFOMETRE_HPP