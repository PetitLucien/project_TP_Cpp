#ifndef __RGB_LCD_H__
#define __RGB_LCD_H__

#include "mbed.h"

// Device I2C Address
#define LCD_ADDRESS     (0X3E)
#define RGB_ADDRESS     (0xc4 >> 1)
#define RGB_ADDRESS_V5  (0x30)

// Color definitions
#define WHITE           0
#define RED             1
#define GREEN           2
#define BLUE            3

#define REG_MODE1       0x00
#define REG_MODE2       0x01
#define REG_OUTPUT      0x08

// Commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// Flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// Flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// Flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// Flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

class rgb_lcd {
public:
    rgb_lcd(PinName sda, PinName scl);

    void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

    void clear();
    void home();

    void noDisplay();
    void display();
    void noBlink();
    void blink();
    void noCursor();
    void cursor();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    void leftToRight();
    void rightToLeft();
    void autoscroll();
    void noAutoscroll();

    void createChar(uint8_t, uint8_t[]);
    void setCursor(uint8_t, uint8_t);

    void print(const char* str);
    void writeChar(char c);

    void command(uint8_t);

    // Color control
    void setRGB(uint8_t r, uint8_t g, uint8_t b);
    void setPWM(uint8_t color, uint8_t pwm);

    void setColor(uint8_t color);
    void setColorAll();
    void setColorWhite();

private:
    void send(uint8_t, uint8_t);
    void setReg(uint8_t addr, uint8_t data);

    I2C _i2c;
    uint8_t rgb_chip_addr;

    uint8_t _displayfunction;
    uint8_t _displaycontrol;
    uint8_t _displaymode;

    uint8_t _initialized;

    uint8_t _numlines, _currline;
};

#endif
