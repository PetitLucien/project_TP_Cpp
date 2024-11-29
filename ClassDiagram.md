:::mermaid
classDiagram
    class Pifometre {
       
    }

    class Ecran {
    
    }

    class rgb_lcd {
        - I2C _i2c
  
        + rgb_lcd(PinName sda, PinName scl)
        + void begin(uint8_t cols, uint8_t rows, uint8_t charsize)
        + void clear()
        + void setCursor(uint8_t, uint8_t)
        + void print(const char* str)
        + void writeChar(char c)
        + void setRGB(uint8_t r, uint8_t g, uint8_t b)
        + void setColor(uint8_t color)
    }
    class I2C ~mbed~{

    }

    class SerialUnbuffer ~mbed~ {
        
    }
    class Keypad{

    }
    class AnalogIN~mbed~{

    }
    class Capteur{
        
    }

    Pifometre *--  Ecran : contient
    Pifometre *--  Capteur : contient
    Pifometre *--  Keypad : contient
    Ecran *-- rgb_lcd 
    rgb_lcd *-- I2C
    SerialUnbuffer --> Keypad
    AnalogIN --> Capteur



:::