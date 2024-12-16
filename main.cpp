#include "Pifometre.hpp"
#include "mbed.h"
#include "string.h"
#include "rgb_lcd.hpp"



int main(void)
{   
    DigitalIn bp(BUTTON1);
    Pifometre monPifometre;
    while (1) {
        if(bp==1){
            monPifometre.run();
        }
        
    }
   
}
