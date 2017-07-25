#ifndef BOX_LEDBAR_H
#define BOX_LEDBAR_H

#include <Arduino.h>

// Avoid name conflict
#define GLB_CMDMODE 0x00  // Work on 8-bit mode
#define GLB_ON      0xff  // 8-bit 1 data
#define GLB_OFF     0x00  // 8-bit 0 data

typedef struct ledbar_s
{

private:
  unsigned int __pinClock;  // Clock pin
  unsigned int __pinData;   // Data pin
  bool __greenToRed;        // Orientation (0 = red to green, 1 = green to red)
  unsigned char __state[10];// Led state, brightness for each LED
  void sendData(unsigned int data);  // Send a word to led bar
  void latchData(void);              // Load data into the latch register
  void setData(unsigned char bits[]);//Set data array

public:
  void init();  // Initialize
  void begin(){pinMode(__pinClock, OUTPUT); pinMode(__pinData, OUTPUT);}
  void setGreenToRed(bool greenToRed);             // (Re)set orientation
  void setLevel(float level);                      // Set level, range from 0 to 10
  void setLed(unsigned char led, float brightness);// Set brightness for a single led, range from 0 to 1
  void toggleLed(unsigned char led);               // Toggle a single led
  void setBits(unsigned int bits);                 // Toggle leds to match given bits
  unsigned int const getBits();                    // Get the current state
} ledbar_s;

#endif
