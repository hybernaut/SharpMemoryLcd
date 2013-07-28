/***********************************
Written by Joshua Oster-Morris/craftycoder.  
BSD license, check license.txt for more information
All text above must be included in any redistribution

This class extends the Adafruit_GFX library.
It can be found at https://github.com/adafruit/Adafruit-GFX-Library
I owe a debt of gratitude to Adafruit for the use of
this interface in the creation of this class.

****************************************/

#ifndef SHARPMEMORYLCD_H
#define SHARPMEMORYLCD_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include <Adafruit_GFX.h>

class SHARPMEMORYLCD : public Adafruit_GFX {
public:
	SHARPMEMORYLCD();
	~SHARPMEMORYLCD();
        void LcdInitialize();
        void LcdAllClearMode();
        void LcdSetMode(int M0, int M2);
        void LcdSendPixels(int num, int state);
        void LcdSetLineAddress(int line);
        void LcdPrintImage(int bitmap, int arraySize);
        void LcdPrintImage(void);
        void LcdPost();
        void LcdPost(int delayTime);
        void LcdStartEXTC(); //frame signal
        void LcdStopEXTC();
        void LcdPrintBuffer();
        void drawPixel(int16_t x, int16_t y, uint16_t color);
        void invert(uint8_t i);
        void LcdClearBuffer();
private:
        unsigned char _buffer[1152];
        int _invert;        
        void LcdSendByte(char byteToSend);
};

#endif

