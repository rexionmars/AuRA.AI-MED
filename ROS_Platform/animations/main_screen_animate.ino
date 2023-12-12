#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_I2C_ADDR 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RST_PIN -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST_PIN);

#define FRAME_DELAY (42)
#define FRAME_COUNT (sizeof(frames) / sizeof(frames[0]))
#define FRAME_WIDTH 64
#define FRAME_HEIGHT 64

// Substitua esta parte do código com os frames reais da animação
const byte PROGMEM frames[][512] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,252,63,255,255,224,0,0,7,254,63,255,255,224,0,0,7,252,63,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,31,255,0,96,0,0,6,0,63,254,0,96,0,0,6,0,63,252,0,96,0,0,6,0,127,252,0,96,0,0,6,0,1,248,0,96,0,0,6,0,1,240,0,96,0,0,6,0,1,240,0,96,0,0,6,0,3,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,7,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,4,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,254,63,255,255,224,0,0,7,254,63,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,252,63,255,255,224,0,0,7,254,63,255,255,224,0,0,7,252,63,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,31,255,0,96,0,0,6,0,63,254,0,96,0,0,6,0,63,252,0,96,0,0,6,0,127,252,0,96,0,0,6,0,1,248,0,96,0,0,6,0,1,240,0,96,0,0,6,0,1,240,0,96,0,0,6,0,3,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,7,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,4,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,254,63,255,255,224,0,0,7,254,63,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,252,63,255,255,224,0,0,7,254,63,255,255,224,0,0,7,252,63,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,31,255,0,96,0,0,6,0,63,254,0,96,0,0,6,0,63,252,0,96,0,0,6,0,127,252,0,96,0,0,6,0,1,248,0,96,0,0,6,0,1,240,0,96,0,0,6,0,1,240,0,96,0,0,6,0,3,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,7,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,4,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,254,63,255,255,224,0,0,7,254,63,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,252,63,255,255,224,0,0,7,254,63,255,255,224,0,0,7,252,63,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,31,255,0,96,0,0,6,0,63,254,0,96,0,0,6,0,63,252,0,96,0,0,6,0,127,252,0,96,0,0,6,0,1,248,0,96,0,0,6,0,1,240,0,96,0,0,6,0,1,240,0,96,0,0,6,0,3,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,7,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,4,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,254,63,255,255,224,0,0,7,254,63,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,15,192,0,0,0,0,63,255,255,240,0,0,0,1,255,255,255,240,0,0,0,3,255,224,0,48,0,0,0,3,128,0,0,48,0,0,0,3,0,0,0,240,0,0,0,3,131,255,255,240,0,0,0,3,255,255,255,248,0,0,0,3,255,255,0,60,0,0,0,7,128,0,0,30,0,0,0,7,0,0,0,15,0,0,0,14,0,0,0,7,0,0,0,28,0,3,255,255,128,0,0,31,248,255,255,255,128,0,0,63,248,255,255,227,128,0,0,63,240,0,0,3,128,0,0,24,0,0,0,3,128,0,0,24,0,0,0,3,128,0,0,24,0,0,0,1,128,0,0,24,0,0,0,1,128,0,0,24,0,0,64,1,128,0,0,24,0,0,64,1,128,0,0,24,0,0,192,1,128,0,0,24,0,1,192,1,128,0,0,24,0,1,192,1,128,0,0,28,0,3,128,1,128,0,0,28,0,7,128,1,128,0,0,28,0,7,128,1,192,0,0,28,0,15,128,1,192,0,0,28,0,15,128,1,192,0,0,28,0,31,128,1,192,0,0,28,0,63,254,1,192,0,0,28,0,63,252,1,192,0,0,28,0,127,252,1,192,0,0,28,0,127,248,1,192,0,0,28,0,255,240,1,192,0,0,12,0,3,240,1,192,0,0,12,0,3,224,1,192,0,0,12,0,3,192,0,192,0,0,12,0,3,192,0,192,0,0,12,0,7,128,0,192,0,0,12,0,7,128,0,192,0,0,12,0,7,0,0,192,0,0,12,0,6,0,0,192,0,0,14,0,6,0,0,192,0,0,14,0,4,0,0,192,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,31,224,0,0,14,0,31,255,255,224,0,0,15,254,63,255,255,192,0,0,7,254,31,0,3,192,0,0,7,192,0,0,7,128,0,0,3,192,0,0,15,0,0,0,0,224,127,255,254,0,0,0,0,255,255,255,248,0,0,0,0,127,255,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,30,0,0,0,0,0,0,63,255,128,0,0,0,0,127,255,255,128,0,0,0,15,255,254,1,128,0,0,0,31,248,0,1,128,0,0,0,28,0,0,15,128,0,0,0,28,0,63,255,128,0,0,0,28,127,255,255,192,0,0,0,31,255,254,0,240,0,0,0,15,252,0,0,120,0,0,0,28,0,0,0,56,0,0,0,56,0,0,0,60,0,0,0,120,0,0,255,252,0,0,0,112,0,255,255,252,0,0,0,227,241,255,248,12,0,0,0,255,241,224,0,14,0,0,0,255,224,0,0,14,0,0,0,224,0,0,0,14,0,0,0,224,0,0,0,14,0,0,0,224,0,0,0,14,0,0,0,224,0,0,0,6,0,0,0,96,0,0,128,6,0,0,0,96,0,1,128,6,0,0,0,96,0,1,128,6,0,0,0,96,0,3,128,7,0,0,0,112,0,3,128,7,0,0,0,112,0,7,128,7,0,0,0,112,0,7,128,7,0,0,0,112,0,15,128,7,0,0,0,112,0,15,0,7,0,0,0,48,0,31,0,3,0,0,0,48,0,63,124,3,0,0,0,48,0,63,252,3,0,0,0,48,0,127,248,3,0,0,0,56,0,127,248,3,128,0,0,56,0,255,240,3,128,0,0,56,0,3,240,3,128,0,0,56,0,3,224,3,128,0,0,56,0,3,224,3,128,0,0,56,0,3,192,1,128,0,0,24,0,3,128,1,128,0,0,24,0,3,128,1,128,0,0,24,0,7,0,1,128,0,0,24,0,7,0,1,192,0,0,28,0,6,0,1,192,0,0,28,0,6,0,1,192,0,0,28,0,4,0,1,192,0,0,28,0,0,0,1,192,0,0,28,0,0,0,1,192,0,0,12,0,0,0,0,192,0,0,12,0,0,0,1,192,0,0,12,0,0,1,255,192,0,0,12,0,3,255,255,192,0,0,14,7,31,255,255,192,0,0,15,255,31,240,7,128,0,0,15,255,0,0,7,0,0,0,7,192,0,0,126,0,0,0,3,192,0,255,254,0,0,0,1,227,255,255,248,0,0,0,0,255,255,248,0,0,0,0,0,127,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,15,192,0,0,0,0,63,255,255,240,0,0,0,1,255,255,255,240,0,0,0,3,255,224,0,48,0,0,0,3,128,0,0,48,0,0,0,3,0,0,0,240,0,0,0,3,131,255,255,240,0,0,0,3,255,255,255,248,0,0,0,3,255,255,0,60,0,0,0,7,128,0,0,30,0,0,0,7,0,0,0,15,0,0,0,14,0,0,0,7,0,0,0,28,0,7,255,255,128,0,0,31,255,143,255,255,128,0,0,63,255,143,255,227,128,0,0,63,254,0,0,3,128,0,0,24,0,0,0,3,128,0,0,24,0,0,0,3,128,0,0,24,0,0,0,1,128,0,0,24,0,0,0,1,128,0,0,24,0,0,8,1,128,0,0,24,0,0,8,1,128,0,0,24,0,0,24,1,128,0,0,24,0,0,24,1,128,0,0,24,0,0,56,1,128,0,0,28,0,0,120,1,128,0,0,28,0,0,112,1,128,0,0,28,0,0,240,1,192,0,0,28,0,1,240,1,192,0,0,28,0,1,240,1,192,0,0,28,0,3,240,1,192,0,0,28,0,3,255,193,192,0,0,28,0,7,255,129,192,0,0,28,0,15,255,129,192,0,0,28,0,15,255,1,192,0,0,28,0,12,126,1,192,0,0,12,0,0,126,1,192,0,0,12,0,0,124,1,192,0,0,12,0,0,120,0,192,0,0,12,0,0,120,0,192,0,0,12,0,0,112,0,192,0,0,12,0,0,240,0,192,0,0,12,0,0,224,0,192,0,0,12,0,0,192,0,192,0,0,14,0,0,192,0,192,0,0,14,0,0,128,0,192,0,0,14,0,0,128,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,31,224,0,0,14,3,195,255,255,224,0,0,15,255,227,255,255,192,0,0,7,255,227,0,3,192,0,0,7,192,0,0,7,128,0,0,3,192,0,0,15,0,0,0,0,224,127,255,254,0,0,0,0,255,255,255,248,0,0,0,0,127,255,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,255,248,127,255,224,0,0,7,255,252,127,255,224,0,0,7,255,248,127,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,64,96,0,0,6,0,0,0,192,96,0,0,6,0,0,0,192,96,0,0,6,0,0,1,128,96,0,0,6,0,0,3,128,96,0,0,6,0,0,3,128,96,0,0,6,0,0,7,128,96,0,0,6,0,0,15,128,96,0,0,6,0,0,31,0,96,0,0,6,0,0,31,0,96,0,0,6,0,0,63,0,96,0,0,6,0,0,127,252,96,0,0,6,0,0,127,248,96,0,0,6,0,0,255,248,96,0,0,6,0,1,255,240,96,0,0,6,0,0,7,224,96,0,0,6,0,0,7,224,96,0,0,6,0,0,7,192,96,0,0,6,0,0,7,128,96,0,0,6,0,0,15,0,96,0,0,6,0,0,15,0,96,0,0,6,0,0,14,0,96,0,0,6,0,0,12,0,96,0,0,6,0,0,12,0,96,0,0,6,0,0,24,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,255,252,127,255,224,0,0,7,255,252,127,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,255,255,252,0,0,0,0,31,255,255,255,128,0,0,0,28,0,63,255,128,0,0,0,28,0,0,1,192,0,0,0,30,0,0,1,192,0,0,0,31,255,255,131,192,0,0,0,31,255,255,255,128,0,0,0,60,15,255,255,128,0,0,0,120,0,0,1,192,0,0,0,224,0,0,0,224,0,0,1,192,0,0,0,112,0,0,1,255,240,0,0,120,0,0,1,255,255,227,255,248,0,0,1,255,255,227,255,248,0,0,1,128,0,1,255,248,0,0,1,128,0,0,0,24,0,0,1,128,0,0,0,24,0,0,1,128,0,0,0,56,0,0,1,128,0,0,0,56,0,0,1,128,0,0,0,56,0,0,3,128,0,0,2,56,0,0,3,128,0,0,6,56,0,0,3,128,0,0,12,56,0,0,3,128,0,0,12,56,0,0,3,128,0,0,28,56,0,0,3,128,0,0,60,56,0,0,3,128,0,0,120,56,0,0,3,128,0,0,248,56,0,0,3,128,0,0,248,56,0,0,3,128,0,1,248,56,0,0,3,128,0,3,240,48,0,0,3,128,0,7,255,240,0,0,3,0,0,7,255,240,0,0,3,0,0,15,255,176,0,0,3,0,0,31,255,48,0,0,3,0,0,0,127,48,0,0,3,0,0,0,126,48,0,0,3,0,0,0,124,48,0,0,3,0,0,0,120,48,0,0,3,0,0,0,248,48,0,0,3,0,0,0,240,112,0,0,3,0,0,0,224,112,0,0,7,0,0,0,192,112,0,0,7,0,0,1,192,112,0,0,7,0,0,1,128,112,0,0,7,0,0,1,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,224,0,0,0,112,0,0,7,255,255,128,0,112,0,0,7,255,255,143,255,224,0,0,3,192,63,135,255,224,0,0,1,224,0,0,3,224,0,0,0,224,0,0,3,192,0,0,0,127,255,252,7,0,0,0,0,127,255,255,255,0,0,0,0,0,63,255,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,1,255,248,0,0,0,0,0,3,255,255,255,0,0,0,0,3,1,255,255,224,0,0,0,3,0,0,127,240,0,0,0,3,128,0,0,112,0,0,0,3,255,192,0,112,0,0,0,7,255,255,248,112,0,0,0,15,15,255,255,240,0,0,0,28,0,1,255,240,0,0,0,56,0,0,0,112,0,0,0,112,0,0,0,56,0,0,0,127,224,0,0,28,0,0,0,127,255,254,0,28,0,0,0,119,255,255,31,238,0,0,0,96,0,127,31,254,0,0,0,96,0,0,15,254,0,0,0,96,0,0,0,14,0,0,0,224,0,0,0,14,0,0,0,224,0,0,0,14,0,0,0,224,0,0,0,14,0,0,0,224,0,0,0,14,0,0,0,224,0,0,0,14,0,0,0,224,0,0,0,30,0,0,0,192,0,0,0,60,0,0,0,192,0,0,0,124,0,0,0,192,0,0,0,236,0,0,0,192,0,0,1,236,0,0,0,192,0,0,1,236,0,0,1,192,0,0,3,220,0,0,1,192,0,0,7,220,0,0,1,224,0,0,15,220,0,0,1,192,0,0,31,156,0,0,1,192,0,0,63,220,0,0,1,192,0,0,63,252,0,0,1,192,0,0,127,248,0,0,1,128,0,0,127,248,0,0,1,128,0,0,3,248,0,0,1,128,0,0,3,248,0,0,1,128,0,0,3,248,0,0,3,128,0,0,7,248,0,0,3,128,0,0,7,184,0,0,3,128,0,0,7,56,0,0,3,128,0,0,15,56,0,0,3,128,0,0,14,56,0,0,3,128,0,0,12,56,0,0,3,128,0,0,24,56,0,0,3,0,0,0,16,48,0,0,3,0,0,0,16,48,0,0,3,0,0,0,0,48,0,0,3,0,0,0,0,48,0,0,3,248,0,0,0,48,0,0,3,255,255,128,0,112,0,0,3,255,255,248,224,112,0,0,1,224,127,248,255,240,0,0,0,224,0,0,255,240,0,0,0,112,0,0,3,224,0,0,0,127,254,0,3,192,0,0,0,63,255,255,199,0,0,0,0,1,255,255,255,0,0,0,0,0,0,31,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,255,255,252,0,0,0,0,31,255,255,255,128,0,0,0,28,0,63,255,128,0,0,0,28,0,0,1,192,0,0,0,30,0,0,1,192,0,0,0,31,255,255,131,192,0,0,0,31,255,255,255,128,0,0,0,60,15,255,255,128,0,0,0,120,0,0,1,192,0,0,0,224,0,0,0,224,0,0,1,192,0,0,0,112,0,0,1,255,240,0,0,120,0,0,1,255,255,255,135,248,0,0,1,255,255,255,143,248,0,0,1,128,0,0,7,248,0,0,1,128,0,0,0,24,0,0,1,128,0,0,0,24,0,0,1,128,0,0,0,56,0,0,1,160,0,0,0,56,0,0,1,224,0,0,0,56,0,0,3,192,0,0,0,56,0,0,3,192,0,0,0,56,0,0,3,192,0,0,0,56,0,0,3,192,0,0,0,56,0,0,3,128,0,0,0,56,0,0,3,128,0,0,0,56,0,0,3,128,0,0,0,120,0,0,3,128,0,0,0,248,0,0,3,128,0,0,0,248,0,0,3,128,0,0,1,248,0,0,3,252,0,0,3,240,0,0,3,252,0,0,7,240,0,0,3,248,0,0,7,240,0,0,3,240,0,0,15,240,0,0,3,224,0,0,31,240,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,128,0,0,0,112,0,0,3,0,0,0,0,112,0,0,3,0,0,0,0,240,0,0,3,0,0,0,0,240,0,0,3,0,0,0,0,240,0,0,7,0,0,0,0,240,0,0,7,0,0,0,1,240,0,0,7,0,0,0,1,240,0,0,7,0,0,0,1,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,224,0,0,0,112,0,0,7,255,255,252,0,112,0,0,7,255,255,254,63,224,0,0,3,192,63,254,63,224,0,0,1,224,0,0,3,224,0,0,0,224,0,0,3,192,0,0,0,127,255,252,7,0,0,0,0,127,255,255,255,0,0,0,0,0,63,255,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,255,255,255,135,224,0,0,7,255,255,255,199,224,0,0,7,255,255,255,135,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,8,0,0,0,96,0,0,6,8,0,0,0,96,0,0,6,24,0,0,0,96,0,0,6,56,0,0,0,96,0,0,6,56,0,0,0,96,0,0,6,112,0,0,0,96,0,0,6,240,0,0,0,96,0,0,7,240,0,0,0,96,0,0,7,240,0,0,0,96,0,0,7,224,0,0,0,96,0,0,7,224,0,0,0,96,0,0,7,255,128,0,0,224,0,0,7,255,128,0,0,224,0,0,7,255,0,0,1,224,0,0,7,254,0,0,1,224,0,0,6,126,0,0,0,96,0,0,6,252,0,0,0,96,0,0,6,248,0,0,0,96,0,0,6,248,0,0,0,96,0,0,7,240,0,0,0,96,0,0,7,224,0,0,0,96,0,0,7,192,0,0,0,96,0,0,7,192,0,0,0,96,0,0,7,128,0,0,0,96,0,0,7,0,0,0,0,96,0,0,7,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,255,255,255,199,224,0,0,7,255,255,255,199,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,255,255,240,0,0,0,1,255,255,255,248,0,0,0,1,255,252,0,56,0,0,0,3,128,0,0,56,0,0,0,3,128,0,0,120,0,0,0,3,193,255,255,248,0,0,0,1,255,255,255,248,0,0,0,1,255,255,240,60,0,0,0,3,128,0,0,30,0,0,0,7,0,0,0,7,0,0,0,14,0,0,0,3,128,0,0,30,0,0,31,199,128,0,0,31,255,255,255,199,128,0,0,31,255,255,255,195,128,0,0,31,255,0,0,1,128,0,0,24,0,0,0,1,128,0,0,24,0,0,0,1,128,0,0,28,0,0,0,1,128,0,0,28,0,0,0,1,128,0,0,28,0,0,0,1,128,0,0,28,1,0,0,1,192,0,0,28,1,0,0,1,192,0,0,28,3,0,0,1,192,0,0,28,7,0,0,1,192,0,0,28,7,0,0,1,192,0,0,28,14,0,0,1,192,0,0,28,30,0,0,1,192,0,0,28,30,0,0,1,192,0,0,28,62,0,0,1,192,0,0,28,62,0,0,1,192,0,0,12,126,0,0,1,192,0,0,12,255,248,0,1,192,0,0,12,255,240,0,0,192,0,0,13,255,224,0,0,192,0,0,15,255,224,0,0,192,0,0,12,15,192,0,0,192,0,0,12,15,128,0,0,192,0,0,12,15,128,0,0,192,0,0,12,15,0,0,0,192,0,0,12,14,0,0,0,192,0,0,14,30,0,0,0,192,0,0,14,28,0,0,0,192,0,0,14,28,0,0,0,224,0,0,14,24,0,0,0,224,0,0,14,16,0,0,0,224,0,0,14,16,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,63,255,241,224,0,0,7,255,255,255,241,224,0,0,7,255,255,248,3,192,0,0,7,192,0,0,7,128,0,0,3,192,0,0,7,0,0,0,0,224,63,255,254,0,0,0,0,255,255,255,252,0,0,0,0,127,255,252,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,31,255,128,0,0,0,0,255,255,255,192,0,0,0,7,255,255,128,192,0,0,0,15,248,0,0,192,0,0,0,14,0,0,1,192,0,0,0,12,0,3,255,192,0,0,0,14,31,255,255,224,0,0,0,15,255,255,240,240,0,0,0,15,255,128,0,56,0,0,0,14,0,0,0,28,0,0,0,28,0,0,0,14,0,0,0,56,0,0,31,142,0,0,0,56,0,127,255,198,0,0,0,119,255,255,255,134,0,0,0,127,255,254,0,6,0,0,0,127,224,0,0,6,0,0,0,112,0,0,0,7,0,0,0,112,0,0,0,7,0,0,0,112,0,0,0,7,0,0,0,112,0,0,0,7,0,0,0,112,0,32,0,7,0,0,0,112,0,32,0,7,0,0,0,112,0,96,0,7,0,0,0,48,0,96,0,3,0,0,0,48,0,224,0,3,0,0,0,48,0,224,0,3,0,0,0,48,1,224,0,3,0,0,0,48,3,224,0,3,0,0,0,56,3,224,0,3,128,0,0,56,7,192,0,3,128,0,0,56,7,192,0,3,128,0,0,56,15,255,0,3,128,0,0,56,15,255,0,3,128,0,0,56,31,254,0,3,128,0,0,24,63,254,0,1,128,0,0,24,63,252,0,1,128,0,0,24,0,248,0,1,128,0,0,24,0,248,0,1,128,0,0,24,0,240,0,1,128,0,0,28,0,240,0,1,192,0,0,28,1,224,0,1,192,0,0,28,1,224,0,1,192,0,0,28,1,192,0,1,192,0,0,28,1,128,0,1,192,0,0,28,1,128,0,1,192,0,0,28,1,0,0,1,192,0,0,12,1,0,0,0,192,0,0,12,0,0,0,0,192,0,0,12,0,0,0,0,192,0,0,12,0,0,0,0,192,0,0,14,0,0,0,0,192,0,0,14,0,1,255,248,192,0,0,14,15,255,255,249,192,0,0,15,255,255,252,7,128,0,0,15,255,192,0,7,0,0,0,7,192,0,0,14,0,0,0,3,192,0,127,254,0,0,0,0,227,255,255,252,0,0,0,0,255,255,255,128,0,0,0,0,127,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,255,255,240,0,0,0,1,255,255,255,248,0,0,0,1,255,252,0,56,0,0,0,3,128,0,0,56,0,0,0,3,128,0,0,120,0,0,0,3,193,255,255,248,0,0,0,1,255,255,255,248,0,0,0,1,255,255,240,60,0,0,0,3,128,0,0,30,0,0,0,7,0,0,0,7,0,0,0,14,0,0,0,3,128,0,0,30,0,1,255,243,128,0,0,31,255,255,255,241,128,0,0,31,255,255,255,241,128,0,0,31,255,248,0,1,128,0,0,24,0,0,0,1,128,0,0,24,0,0,0,1,128,0,0,28,0,0,0,1,128,0,0,28,0,0,0,1,128,0,0,28,0,0,64,1,128,0,0,28,0,0,64,1,192,0,0,28,0,0,192,1,192,0,0,28,0,1,192,1,192,0,0,28,0,1,128,1,192,0,0,28,0,3,128,1,192,0,0,28,0,7,128,1,192,0,0,28,0,7,128,1,192,0,0,28,0,15,128,1,192,0,0,28,0,15,128,1,192,0,0,28,0,31,0,1,192,0,0,12,0,63,252,1,192,0,0,12,0,63,252,1,192,0,0,12,0,127,248,0,192,0,0,12,0,255,248,0,192,0,0,12,0,255,240,0,192,0,0,12,0,3,224,0,192,0,0,12,0,3,224,0,192,0,0,12,0,7,192,0,192,0,0,12,0,7,128,0,192,0,0,12,0,7,128,0,192,0,0,14,0,7,0,0,192,0,0,14,0,7,0,0,192,0,0,14,0,6,0,0,224,0,0,14,0,4,0,0,224,0,0,14,0,12,0,0,224,0,0,14,0,8,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,14,0,0,0,120,224,0,0,14,31,255,255,252,224,0,0,7,255,255,255,253,192,0,0,7,255,255,255,243,192,0,0,7,240,0,0,7,128,0,0,3,192,0,0,7,0,0,0,0,224,63,255,254,0,0,0,0,255,255,255,252,0,0,0,0,127,255,252,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,255,255,255,254,224,0,0,7,255,255,255,254,96,0,0,7,255,255,255,254,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,128,96,0,0,6,0,0,1,0,96,0,0,6,0,0,3,0,96,0,0,6,0,0,3,0,96,0,0,6,0,0,7,0,96,0,0,6,0,0,15,0,96,0,0,6,0,0,30,0,96,0,0,6,0,0,30,0,96,0,0,6,0,0,62,0,96,0,0,6,0,0,126,0,96,0,0,6,0,0,126,0,96,0,0,6,0,0,255,240,96,0,0,6,0,1,255,240,96,0,0,6,0,1,255,224,96,0,0,6,0,3,255,224,96,0,0,6,0,0,15,192,96,0,0,6,0,0,15,128,96,0,0,6,0,0,31,0,96,0,0,6,0,0,31,0,96,0,0,6,0,0,30,0,96,0,0,6,0,0,28,0,96,0,0,6,0,0,28,0,96,0,0,6,0,0,56,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,32,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,255,255,255,254,224,0,0,7,255,255,255,254,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,255,255,248,0,0,0,0,31,255,255,255,0,0,0,0,63,255,255,255,0,0,0,0,56,0,0,3,128,0,0,0,56,0,0,3,128,0,0,0,63,255,248,7,128,0,0,0,63,255,255,255,0,0,0,0,127,255,255,255,128,0,0,0,240,0,0,3,128,0,0,0,224,0,0,1,192,0,0,1,192,0,0,0,224,0,0,3,128,0,0,0,112,0,0,3,159,255,255,255,240,0,0,3,159,255,255,255,240,0,0,3,128,0,127,255,240,0,0,3,0,0,0,0,48,0,0,3,0,0,0,0,48,0,0,3,0,0,0,0,48,0,0,3,0,0,0,0,48,0,0,3,0,0,0,0,48,0,0,3,0,0,0,4,48,0,0,3,0,0,0,4,48,0,0,3,0,0,0,12,48,0,0,3,0,0,0,28,48,0,0,3,0,0,0,28,48,0,0,3,0,0,0,56,48,0,0,3,0,0,0,120,112,0,0,3,0,0,0,248,112,0,0,3,0,0,0,248,112,0,0,3,0,0,1,240,112,0,0,3,0,0,3,240,112,0,0,3,0,0,7,255,240,0,0,7,0,0,7,255,240,0,0,7,0,0,15,255,240,0,0,7,0,0,31,255,112,0,0,7,0,0,0,126,112,0,0,7,0,0,0,126,112,0,0,7,0,0,0,124,112,0,0,7,0,0,0,120,112,0,0,7,0,0,0,248,112,0,0,7,0,0,0,240,112,0,0,7,0,0,0,224,112,0,0,7,0,0,0,192,112,0,0,7,0,0,1,192,112,0,0,7,0,0,1,128,112,0,0,7,0,0,1,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,96,0,0,7,0,0,0,0,96,0,0,7,0,0,0,0,96,0,0,7,63,255,0,0,96,0,0,7,63,255,255,255,224,0,0,3,159,255,255,255,224,0,0,3,192,0,0,3,224,0,0,0,224,0,0,3,192,0,0,0,127,255,0,7,0,0,0,0,127,255,255,254,0,0,0,0,31,255,255,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,3,240,0,0,0,0,0,0,15,255,255,252,0,0,0,0,15,255,255,255,128,0,0,0,12,0,7,255,192,0,0,0,12,0,0,1,192,0,0,0,15,0,0,0,192,0,0,0,15,255,255,193,192,0,0,0,31,255,255,255,192,0,0,0,60,0,255,255,192,0,0,0,120,0,0,1,224,0,0,0,240,0,0,0,224,0,0,0,224,0,0,0,112,0,0,1,252,127,192,0,56,0,0,1,252,127,255,255,248,0,0,1,192,127,255,255,252,0,0,1,192,0,0,255,252,0,0,1,192,0,0,0,28,0,0,1,192,0,0,0,24,0,0,1,192,0,0,0,24,0,0,1,128,0,0,0,24,0,0,1,128,0,0,0,24,0,0,1,128,0,0,0,24,0,0,1,128,0,0,0,56,0,0,1,128,0,0,0,56,0,0,1,128,0,0,0,120,0,0,1,128,0,0,0,248,0,0,1,128,0,0,1,248,0,0,3,128,0,0,1,248,0,0,3,128,0,0,3,248,0,0,3,128,0,0,7,248,0,0,3,128,0,0,15,248,0,0,3,224,0,0,15,248,0,0,3,224,0,0,31,248,0,0,3,192,0,0,63,248,0,0,3,128,0,0,127,248,0,0,3,128,0,0,127,248,0,0,3,128,0,0,1,240,0,0,3,128,0,0,3,240,0,0,3,0,0,0,3,240,0,0,3,0,0,0,3,240,0,0,3,0,0,0,3,240,0,0,3,0,0,0,7,176,0,0,3,0,0,0,7,48,0,0,3,0,0,0,6,48,0,0,3,0,0,0,6,112,0,0,3,0,0,0,12,112,0,0,7,0,0,0,8,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,224,0,0,0,112,0,0,7,241,255,255,128,112,0,0,3,241,255,255,255,224,0,0,3,192,0,255,255,224,0,0,1,224,0,0,3,224,0,0,0,240,0,0,3,192,0,0,0,127,255,254,7,0,0,0,0,31,255,255,255,0,0,0,0,0,7,255,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,255,255,248,0,0,0,0,31,255,255,255,0,0,0,0,63,255,255,255,0,0,0,0,56,0,0,3,128,0,0,0,56,0,0,3,128,0,0,0,63,255,248,7,128,0,0,0,63,255,255,255,0,0,0,0,127,255,255,255,128,0,0,0,240,0,0,3,128,0,0,0,224,0,0,1,192,0,0,1,192,0,0,0,224,0,0,3,192,0,0,0,112,0,0,3,255,199,255,255,240,0,0,3,255,199,255,255,240,0,0,3,128,1,255,255,240,0,0,3,0,0,0,0,48,0,0,3,0,0,0,0,48,0,0,3,0,0,0,0,48,0,0,3,0,0,0,0,48,0,0,3,16,0,0,0,48,0,0,3,32,0,0,0,48,0,0,3,96,0,0,0,48,0,0,3,224,0,0,0,48,0,0,3,224,0,0,0,48,0,0,3,192,0,0,0,48,0,0,3,192,0,0,0,48,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,128,0,0,0,112,0,0,3,128,0,0,0,240,0,0,3,248,0,0,1,240,0,0,3,254,0,0,1,240,0,0,7,252,0,0,3,240,0,0,7,248,0,0,7,240,0,0,7,248,0,0,15,240,0,0,7,240,0,0,0,112,0,0,7,224,0,0,0,112,0,0,7,224,0,0,0,112,0,0,7,192,0,0,0,112,0,0,7,128,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,240,0,0,7,0,0,0,0,240,0,0,7,0,0,0,0,240,0,0,7,0,0,0,0,112,0,0,7,0,0,0,0,96,0,0,7,0,0,0,0,96,0,0,7,0,0,0,0,96,0,0,7,255,135,0,0,96,0,0,7,255,143,255,255,224,0,0,7,255,135,255,255,224,0,0,3,192,0,0,3,224,0,0,0,224,0,0,3,192,0,0,0,127,255,0,7,0,0,0,0,127,255,255,254,0,0,0,0,31,255,255,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,255,254,31,255,224,0,0,7,255,254,63,255,224,0,0,7,255,254,31,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,6,0,0,0,96,0,0,6,4,0,0,0,96,0,0,6,12,0,0,0,96,0,0,6,28,0,0,0,96,0,0,6,28,0,0,0,96,0,0,6,60,0,0,0,96,0,0,6,120,0,0,0,96,0,0,6,120,0,0,0,96,0,0,6,248,0,0,0,96,0,0,7,248,0,0,0,96,0,0,7,240,0,0,0,96,0,0,7,255,192,0,0,96,0,0,7,255,192,0,0,96,0,0,7,255,128,0,0,224,0,0,7,255,0,0,0,224,0,0,6,63,0,0,0,96,0,0,6,62,0,0,0,96,0,0,6,124,0,0,0,96,0,0,6,124,0,0,0,96,0,0,6,120,0,0,0,96,0,0,6,112,0,0,0,96,0,0,6,112,0,0,0,96,0,0,6,224,0,0,0,96,0,0,6,192,0,0,0,96,0,0,6,192,0,0,0,96,0,0,7,128,0,0,0,96,0,0,7,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,255,254,63,255,224,0,0,7,255,254,63,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,255,255,248,127,224,0,0,7,255,255,252,127,224,0,0,7,255,255,248,127,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,64,0,0,96,0,0,6,0,192,0,0,96,0,0,6,0,192,0,0,96,0,0,6,1,192,0,0,96,0,0,6,3,128,0,0,96,0,0,6,3,128,0,0,96,0,0,6,7,128,0,0,96,0,0,6,15,128,0,0,96,0,0,6,15,128,0,0,96,0,0,6,31,0,0,0,96,0,0,6,63,0,0,0,96,0,0,6,63,252,0,0,96,0,0,6,127,252,0,0,96,0,0,6,255,248,0,0,96,0,0,7,255,240,0,0,96,0,0,6,7,224,0,0,96,0,0,6,7,224,0,0,96,0,0,6,7,192,0,0,96,0,0,6,7,128,0,0,96,0,0,6,7,128,0,0,96,0,0,6,15,0,0,0,96,0,0,6,14,0,0,0,96,0,0,6,14,0,0,0,96,0,0,6,12,0,0,0,96,0,0,6,8,0,0,0,96,0,0,6,16,0,0,0,96,0,0,6,16,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,255,255,252,127,224,0,0,7,255,255,252,127,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,255,255,255,240,224,0,0,7,255,255,255,241,224,0,0,7,255,255,255,240,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,8,0,0,96,0,0,6,0,8,0,0,96,0,0,6,0,24,0,0,96,0,0,6,0,56,0,0,96,0,0,6,0,56,0,0,96,0,0,6,0,112,0,0,96,0,0,6,0,240,0,0,96,0,0,6,1,240,0,0,96,0,0,6,1,240,0,0,96,0,0,6,3,240,0,0,96,0,0,6,7,224,0,0,96,0,0,6,7,255,128,0,96,0,0,6,15,255,128,0,96,0,0,6,31,255,0,0,96,0,0,6,31,254,0,0,96,0,0,6,0,126,0,0,96,0,0,6,0,252,0,0,96,0,0,6,0,248,0,0,96,0,0,6,0,248,0,0,96,0,0,6,0,240,0,0,96,0,0,6,0,224,0,0,96,0,0,6,1,192,0,0,96,0,0,6,1,192,0,0,96,0,0,6,1,128,0,0,96,0,0,6,1,0,0,0,96,0,0,6,1,0,0,0,96,0,0,6,2,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,255,255,255,241,224,0,0,7,255,255,255,241,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,63,255,255,255,224,0,0,6,127,255,255,255,224,0,0,6,63,255,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,1,0,0,96,0,0,6,0,3,0,0,96,0,0,6,0,3,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,14,0,0,96,0,0,6,0,14,0,0,96,0,0,6,0,30,0,0,96,0,0,6,0,62,0,0,96,0,0,6,0,124,0,0,96,0,0,6,0,124,0,0,96,0,0,6,0,252,0,0,96,0,0,6,1,255,240,0,96,0,0,6,1,255,224,0,96,0,0,6,3,255,224,0,96,0,0,6,7,255,192,0,96,0,0,6,0,31,128,0,96,0,0,6,0,31,128,0,96,0,0,6,0,31,0,0,96,0,0,6,0,30,0,0,96,0,0,6,0,60,0,0,96,0,0,6,0,60,0,0,96,0,0,6,0,56,0,0,96,0,0,6,0,48,0,0,96,0,0,6,0,48,0,0,96,0,0,6,0,96,0,0,96,0,0,6,0,64,0,0,96,0,0,6,0,64,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,127,255,255,255,224,0,0,7,127,255,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,195,255,255,255,224,0,0,7,227,255,255,255,224,0,0,7,195,255,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,64,0,96,0,0,6,0,0,192,0,96,0,0,6,0,0,192,0,96,0,0,6,0,1,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,7,128,0,96,0,0,6,0,15,128,0,96,0,0,6,0,31,0,0,96,0,0,6,0,31,0,0,96,0,0,6,0,63,0,0,96,0,0,6,0,127,252,0,96,0,0,6,0,127,248,0,96,0,0,6,0,255,248,0,96,0,0,6,1,255,240,0,96,0,0,6,0,7,224,0,96,0,0,6,0,7,224,0,96,0,0,6,0,7,192,0,96,0,0,6,0,7,128,0,96,0,0,6,0,15,0,0,96,0,0,6,0,15,0,0,96,0,0,6,0,14,0,0,96,0,0,6,0,12,0,0,96,0,0,6,0,12,0,0,96,0,0,6,0,24,0,0,96,0,0,6,0,16,0,0,96,0,0,6,0,16,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,227,255,255,255,224,0,0,7,227,255,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,248,127,255,255,224,0,0,7,252,127,255,255,224,0,0,7,248,127,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,32,0,96,0,0,6,0,0,32,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,224,0,96,0,0,6,0,1,192,0,96,0,0,6,0,1,192,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,15,128,0,96,0,0,6,0,31,128,0,96,0,0,6,0,31,254,0,96,0,0,6,0,63,254,0,96,0,0,6,0,127,252,0,96,0,0,6,0,127,248,0,96,0,0,6,0,3,240,0,96,0,0,6,0,3,240,0,96,0,0,6,0,3,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,128,0,96,0,0,6,0,7,0,0,96,0,0,6,0,7,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,4,0,0,96,0,0,6,0,12,0,0,96,0,0,6,0,8,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,252,127,255,255,224,0,0,7,252,127,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,252,63,255,255,224,0,0,7,254,63,255,255,224,0,0,7,252,63,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,31,255,0,96,0,0,6,0,63,254,0,96,0,0,6,0,63,252,0,96,0,0,6,0,127,252,0,96,0,0,6,0,1,248,0,96,0,0,6,0,1,240,0,96,0,0,6,0,3,240,0,96,0,0,6,0,3,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,7,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,4,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,254,63,255,255,224,0,0,7,254,63,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,252,63,255,255,224,0,0,7,254,63,255,255,224,0,0,7,252,63,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,31,255,0,96,0,0,6,0,63,254,0,96,0,0,6,0,63,252,0,96,0,0,6,0,127,252,0,96,0,0,6,0,1,248,0,96,0,0,6,0,1,240,0,96,0,0,6,0,3,240,0,96,0,0,6,0,3,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,7,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,4,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,254,63,255,255,224,0,0,7,254,63,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,255,224,0,0,0,0,63,255,255,252,0,0,0,0,127,255,255,254,0,0,0,0,112,0,0,14,0,0,0,0,96,0,0,6,0,0,0,0,112,0,0,14,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,224,0,0,7,0,0,0,1,192,0,0,3,128,0,0,3,128,0,0,1,192,0,0,7,0,0,0,0,224,0,0,7,252,63,255,255,224,0,0,7,254,63,255,255,224,0,0,7,252,63,255,255,224,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,16,0,96,0,0,6,0,0,48,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,96,0,96,0,0,6,0,0,224,0,96,0,0,6,0,1,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,192,0,96,0,0,6,0,7,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,15,192,0,96,0,0,6,0,31,255,0,96,0,0,6,0,63,254,0,96,0,0,6,0,63,252,0,96,0,0,6,0,127,252,0,96,0,0,6,0,1,248,0,96,0,0,6,0,1,240,0,96,0,0,6,0,3,240,0,96,0,0,6,0,3,224,0,96,0,0,6,0,3,192,0,96,0,0,6,0,3,128,0,96,0,0,6,0,3,128,0,96,0,0,6,0,7,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,6,0,0,96,0,0,6,0,4,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,6,0,0,0,0,96,0,0,7,0,0,0,0,224,0,0,7,254,63,255,255,224,0,0,7,254,63,255,255,224,0,0,3,192,0,0,3,192,0,0,3,192,0,0,3,192,0,0,0,224,0,0,7,0,0,0,0,127,255,255,254,0,0,0,0,127,255,255,254,0,0,0,0,15,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

};


void setup() {
  Serial.begin(115200);

  Wire.begin(14, 15, 100000); // Substitua pelos pinos SDA e SCL do seu projeto

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR))
  {
    Serial.println("SSD1306 OLED display failed to initialize.");
    while (true);
  }
}

int frame = 0;
void loop() {
  display.clearDisplay();
  display.drawBitmap(32, 0, frames[frame], 64, 64, 1); // Substitua os valores de largura e altura conforme necessário
  display.display();
  frame = (frame + 1) % FRAME_COUNT;
  delay(FRAME_DELAY);
}
