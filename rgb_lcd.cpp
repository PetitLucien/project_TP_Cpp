#include "rgb_lcd.hpp"

rgb_lcd::rgb_lcd(PinName sda, PinName scl) : _i2c(sda, scl) {
    _initialized = 0;
    rgb_chip_addr = RGB_ADDRESS;
}

void rgb_lcd::begin(uint8_t cols, uint8_t rows, uint8_t charsize) {
    _numlines = rows;
    _currline = 0;

    _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
    if (rows > 1) {
        _displayfunction |= LCD_2LINE;
    }

    // Initialization sequence
    ThisThread::sleep_for(50ms);
    command(LCD_FUNCTIONSET | _displayfunction);
    ThisThread::sleep_for(5ms);

    command(LCD_FUNCTIONSET | _displayfunction);
    ThisThread::sleep_for(1ms);

    command(LCD_FUNCTIONSET | _displayfunction);
    command(LCD_FUNCTIONSET | _displayfunction);

    // Turn the display on with no cursor or blinking
    _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    display();

    // Clear the display
    clear();

    // Set the entry mode
    _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
    command(LCD_ENTRYMODESET | _displaymode);

    // Initialize backlight
    setReg(REG_MODE1, 0);
    setReg(REG_OUTPUT, 0xFF);
    setReg(REG_MODE2, 0x20);
    setColorWhite();
}

void rgb_lcd::clear() {
    command(LCD_CLEARDISPLAY);
    ThisThread::sleep_for(2ms);
}

void rgb_lcd::home() {
    command(LCD_RETURNHOME);
    ThisThread::sleep_for(2ms);
}

void rgb_lcd::setRGB(uint8_t r, uint8_t g, uint8_t b) {
    setReg(0x04, r);
    setReg(0x03, g);
    setReg(0x02, b);
}

void rgb_lcd::setColorWhite() {
    // Set the backlight color to white (R = 255, G = 255, B = 255)
    setRGB(255, 255, 255);
}
void rgb_lcd::setCursor(uint8_t col, uint8_t row) {

    col = (row == 0 ? col | 0x80 : col | 0xc0);
    char dta[2] = {0x80, col};
    _i2c.write(LCD_ADDRESS << 1, dta, 2);

}

void rgb_lcd::display() {
    _displaycontrol |= LCD_DISPLAYON;
    command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void rgb_lcd::noDisplay() {
    _displaycontrol &= ~LCD_DISPLAYON;
    command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void rgb_lcd::command(uint8_t value) {
    send(0x80, value);
}

void rgb_lcd::send(uint8_t mode, uint8_t data) {
    char cmd[2] = {mode, data};
    _i2c.write(LCD_ADDRESS << 1, cmd, 2);
}

void rgb_lcd::setReg(uint8_t addr, uint8_t data) {
    char cmd[2] = {addr, data};
    _i2c.write(rgb_chip_addr << 1, cmd, 2);
}

void rgb_lcd::print(const char* str) {
    while (*str) {
        writeChar(*str++);
    }
}

void rgb_lcd::writeChar(char c) {
    send(0x40, c);
}
