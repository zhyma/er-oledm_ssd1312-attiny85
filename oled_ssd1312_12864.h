/***************************************************
//Web: http://www.buydisplay.com
EastRising Technology Co.,LTD
****************************************************/
  
#ifndef _er_oled_H_
#define _er_oled_H_

#include <Arduino.h>
#include <avr/pgmspace.h>

//#define _software_SPI

#define WIDTH 128
#define HEIGHT 64
#define PAGES HEIGHT/8

#ifdef _software_SPI
#define OLED_SDA 1
#define OLED_SCL 2
#endif

#define OLED_RST 3
#define OLED_DC  4

/**** reference from buydisplay.com *****/
// #define OLED_INIT_LEN   26
// const uint8_t OLED_INIT_CMD[] PROGMEM = {
//   0xAE,             // display off
//   //USE_HORIZONTAL 128COL*8PAGE
//   0x20, 0x02,       //Set Memory addressing mode Com scan direction 
////   0xA1,0xC0,        //set segment remap Com scan direction
//
////   0x00, 0x10, 0xB0, // set lower column address, higher column address, and page address
////   0x40,             //set display start lines
//   0x81, 0x00,       //contract control, default 0x80
////   0xA4,             // disable entire display on (0xA4, 0xA5)
////   0xA6,             // normal (0xA7 is reverse)
//   0xA8, 0x3F,       // multiplex ratio, duty = 1/64
//
////   0xD3, 0x00,       // set display offset
////   0xD5, 0x80,       // set osc division
////   0xD9, 0x22,       // set pre-charge period
//   0xDA, 0x10,       // Set SEG Pins Hardware Configuration
////   0xDB, 0x30,       // set vcomh
//   0x8D, 0x12,       // set charge pump enable 0x12:7.5V; 0x52:8V;  0x72:9V;  0x92:10V
//   
//   0xAF
// };

#define OLED_INIT_LEN   14
const uint8_t OLED_INIT_CMD[] PROGMEM = {
  0xA8, 0x3F,       // set multiplex (HEIGHT-1): 0x1F for 128x32, 0x3F for 128x64 
  0x22, 0x00, 0x03, // set min and max page
  0x20, 0x00,       // set horizontal memory addressing mode
  0xDA, 0x10,       // set COM pins hardware configuration to sequential
  0x8D, 0x12,       // enable charge pump
  0xAF,             // switch on OLED
  0xA1, 0xC8        // flip the screen
};

///**** "working set up" backup ****/
//#define OLED_INIT_LEN   14
//const uint8_t OLED_INIT_CMD[] PROGMEM = {
//  0xA8, 0x3F,       // set multiplex (HEIGHT-1): 0x1F for 128x32, 0x3F for 128x64 
//  0x22, 0x00, 0x03, // set min and max page
//  0x20, 0x00,       // set horizontal memory addressing mode
//  0xDA, 0x02,       // set COM pins hardware configuration to sequential
//  0x8D, 0x12,       // enable charge pump
//  0xAF,             // switch on OLED
//  0xA1, 0xC8        // flip the screen
//};


class ErOLED {
  public:
    void init();
    //void er_oled_display(uint8_t* buffer);
    void SPIWrite(uint8_t data);
    void sendCommand(uint8_t cmd);
    void drawBitmap(const byte *bitmap, byte X, byte Y, uint8_t w, uint8_t h);
    void setCursorXY(byte X, byte Y);
};

extern ErOLED oled;

#endif
