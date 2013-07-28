#include "SharpMemoryLcd.h"
#include <avr/pgmspace.h>

        static const int DISP = 2;
        static const int EXTC = 3;
        static const int EXTM = 4; //this can just be pulled high on your PCB if you need the pin
        static const int SI = 11;
        static const int SCS = 12;
        static const int SCLK = 13;
        
#define ARRAYSIZE 1152

const unsigned char ARDUINOBMP[ARRAYSIZE] PROGMEM = {
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,31,128,255,255,255,255,3,240,255,63,
	252,255,3,0,252,255,255,127,0,0,255,63,
	252,255,0,0,224,255,255,31,0,0,252,63,
	252,63,0,0,192,255,255,7,0,0,248,63,
	252,15,0,0,0,255,255,1,0,0,224,63,
	252,7,0,0,0,254,255,0,0,0,192,63,
	252,3,0,0,0,248,127,0,0,0,128,63,
	252,1,192,63,0,240,63,0,248,7,0,63,
	252,0,248,255,1,224,31,0,254,63,0,62,
	252,0,252,255,7,192,15,128,255,127,0,60,
	124,0,255,255,15,192,7,224,255,255,1,60,
	124,128,255,255,31,128,3,240,255,255,3,56,
	60,192,255,255,127,0,1,248,255,255,7,56,
	60,192,255,255,255,0,0,252,255,255,15,48,
	28,224,255,255,255,0,0,254,31,255,15,48,
	28,224,255,255,255,1,0,255,31,255,31,48,
	28,240,255,255,255,3,128,255,31,255,31,32,
	28,240,255,255,255,7,128,255,31,255,63,32,
	12,240,255,255,255,7,192,255,15,254,63,32,
	12,248,15,0,254,15,224,255,0,224,63,32,
	12,248,15,0,254,15,224,255,0,224,63,32,
	12,248,15,0,254,15,224,255,0,224,63,32,
	12,248,255,255,255,15,192,255,15,254,63,32,
	12,240,255,255,255,7,192,255,31,255,63,32,
	28,240,255,255,255,3,128,255,31,255,31,32,
	28,240,255,255,255,3,0,255,31,255,31,48,
	28,224,255,255,255,1,0,255,31,255,31,48,
	28,224,255,255,255,0,0,254,255,255,15,48,
	60,192,255,255,127,0,0,252,255,255,7,56,
	60,128,255,255,63,0,3,248,255,255,3,56,
	124,0,255,255,31,128,3,240,255,255,1,60,
	124,0,254,255,7,192,7,192,255,255,0,60,
	252,0,248,255,3,224,15,0,255,127,0,62,
	252,1,224,127,0,240,31,0,252,15,0,63,
	252,3,0,6,0,248,63,0,192,0,0,63,
	252,7,0,0,0,252,127,0,0,0,192,63,
	252,15,0,0,0,254,255,1,0,0,224,63,
	252,31,0,0,128,255,255,3,0,0,240,63,
	252,127,0,0,224,255,255,15,0,0,248,63,
	252,255,1,0,248,255,255,63,0,0,255,63,
	252,255,7,0,254,255,255,255,1,192,255,63,
	252,255,255,240,255,255,255,255,31,254,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	252,255,255,255,255,255,255,255,255,255,255,63,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0
};
SHARPMEMORYLCD::SHARPMEMORYLCD() {
  pinMode(DISP, OUTPUT);
  pinMode(EXTC, OUTPUT);
  pinMode(EXTM, OUTPUT); //this can be ignored and you can just pull the pin high on your PCB
  pinMode(SI, OUTPUT);
  pinMode(SCS, OUTPUT);
  pinMode(SCLK, OUTPUT);
  TCCR2B = TCCR2B & 0b11111000 | 0x07; //this sets the EXTC timer on pin 3. you need to change this to move pins
  constructor(96, 96);
  LcdClearBuffer();
}

SHARPMEMORYLCD::~SHARPMEMORYLCD(){/*nothing to destruct*/}

void SHARPMEMORYLCD::LcdInitialize() {
  digitalWrite(EXTM,HIGH);
  digitalWrite(DISP,HIGH);
  delayMicroseconds(50); 
}
void SHARPMEMORYLCD::LcdClearBuffer() {
  for(int x = 0;x < ARRAYSIZE;x++) {
    _buffer[x] = 255;
  }
  _invert = 0;
}
void SHARPMEMORYLCD::LcdAllClearMode() {
  int i;
  
  digitalWrite(SCS,HIGH);
  
  LcdSetMode(LOW, HIGH);
  
  for(i = 0; i < 14; i++){ //Send 14 bits of dummy data
    digitalWrite(SI,LOW);
    delayMicroseconds(3);
    LcdPost(-2);
  }

  digitalWrite(SCS,LOW);
  LcdClearBuffer();
}
void SHARPMEMORYLCD::LcdSetMode(int M0, int M2) {
  int i;
  digitalWrite(SI,M0);
  LcdPost();  
  digitalWrite(SI,HIGH);
  LcdPost();
  digitalWrite(SI,M2);
  LcdPost();
  for(i = 0; i < 5; i++){ //Send 5 bits of dummy data
    digitalWrite(SI,LOW);
    LcdPost();
  }    
}
void SHARPMEMORYLCD::LcdSendPixels(int num, int state) {
  int i;
  for(i = 0; i < num; i++){
      digitalWrite(SI,state);
      LcdPost(0);
  }  
}
void SHARPMEMORYLCD::LcdSetLineAddress(int line) {
  int i;  
  unsigned char tmp;
  
  for (i = 0; i < 8; i++){
    tmp = (line & 1);
    if (tmp == 1){
      digitalWrite(SI,HIGH);
      LcdPost(0);
    } else {
    digitalWrite(SI,LOW);
      LcdPost(0);
    }
    line = line >> 1;
  } 
}
void SHARPMEMORYLCD::LcdPrintImage(void)
{
  LcdPrintImage(0,ARRAYSIZE);
}
void SHARPMEMORYLCD::LcdPrintImage(int bitmap, int arraySize)
{
  int i,b;
  unsigned char LineCount;
  char temp;

  LineCount = 1;

  digitalWrite(SCS,HIGH);
  LcdSetMode(HIGH,LOW);

  LcdSetLineAddress(LineCount);

  for(i = 0; i < arraySize; i++){
    if(bitmap == 0)
      temp = pgm_read_byte(&ARDUINOBMP[i]);
    else if(bitmap == -1)
      temp = _buffer[i];
    if(_invert == 1) {
      temp = ~temp;
    }
    LcdSendByte(temp);     
    if((i+1) % 12 == 0){
      LcdSendPixels(8,0);
      LineCount++;
      if(LineCount < 97)
        LcdSetLineAddress(LineCount);
    }
  }
  delayMicroseconds(1);
  digitalWrite(SCS,LOW);
}
void SHARPMEMORYLCD::LcdPost() {
  LcdPost(1);
}
void SHARPMEMORYLCD::LcdPost(int delayTime) {
  digitalWrite(SCLK,HIGH);
  if(delayTime > 0) {
    delay(delayTime);
  }
  if(delayTime < 0) {
    delayMicroseconds(delayTime);
  }
  digitalWrite(SCLK,LOW);
}
void SHARPMEMORYLCD::LcdStartEXTC() {
  analogWrite(EXTC,127);
}
void SHARPMEMORYLCD::LcdStopEXTC() {
  analogWrite(EXTC,0);
}
void SHARPMEMORYLCD::LcdSendByte(char byteToSend) {
  for(int b = 0; b < 8; b++){
      if(byteToSend & 1){
        digitalWrite(SI,HIGH);
        delayMicroseconds(1);
        LcdPost(0);
      } else {
        digitalWrite(SI,LOW);
        delayMicroseconds(1);
        LcdPost(0);
      }
      byteToSend = byteToSend >> 1;
    }
}
void SHARPMEMORYLCD::LcdPrintBuffer() {
  LcdPrintImage(-1,ARRAYSIZE);
}
void SHARPMEMORYLCD::invert(uint8_t i) {
  _invert = i;
}
void SHARPMEMORYLCD::drawPixel(int16_t x, int16_t y, uint16_t color) {
  int xloc = ((y*12))+x/8;
  int shift = (x % 8);
  if (color)
    _buffer[xloc] |= (1 << shift);
  else
    _buffer[xloc] &= ~(1 << shift);
}
