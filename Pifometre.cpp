#include "Pifometre.hpp"
#include <cstdint>
#include <cstdio>
#include <iostream>

Pifometre::Pifometre() 
    : screen(0, 0, 10, 1, 0, 1),  
      distanceSensor(A0),  
      clavier(PC_1, PC_0) 
{
    // Initialization logic
}

Pifometre::~Pifometre() {
    // Cleanup logic
}

void Pifometre::run() {
    string strguess{" "};
    uint16_t intguess{0};
    distanceSensor.readCapteur();
    printf("Distance mesure: %d cm\r\n", distanceSensor.getDistance());

    while(getguessOk()==0)
    {   strguess.clear();
        screen.clearDisplay();
        screen.writeMessage("Guess the dist.:");
        screen.writePrompt("guess(cm):");
        intguess=clavier.getGuess(strguess);
        screen.writeGuess(strguess);
        DistanceVSguess(distanceSensor.getDistance(),intguess);
        ThisThread::sleep_for(2s);
    }
    this->resetguessOk();   
}


void Pifometre::DistanceVSguess(uint16_t distance, int16_t guess){
    float error=((float(guess)/distance)*100)-100;
    if (error>=-1 && error<=1)
    {
        screen.writeMessage("Parfait!");
        this->setguessOk();
    }
    
    else if(error>=-5 && error<=5)
    {
        screen.writeMessage("suffisant");
        this->setguessOk();
    }
    else if (error>=-50 && error<=50)
    {
        screen.writeMessage("Pas mal");
    }
    else if (error>=-100 && error<=100)
    {
        screen.writeMessage("on a vu mieux");
    }
    else if(error>=-200 && error<=200)
    {
        screen.writeMessage("C'est loin");
    }
    else
    {
        screen.writeMessage("Vraiment pas bon");
    }
       
}