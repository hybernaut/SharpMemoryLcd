#include <Adafruit_GFX.h>
#include <SharpMemoryLcd.h>

SHARPMEMORYLCD lcd;

void setup() {                
  Serial.begin(9600);
  lcd.LcdInitialize();
  lcd.LcdAllClearMode();
  lcd.LcdStartEXTC();
  
}

void loop() {
  lcd.LcdPrintImage();
  delay(3000);
  lcd.LcdStopEXTC();
  lcd.LcdAllClearMode();
  lcd.LcdStartEXTC();
  lcd.setCursor(1,6);
  lcd.setTextColor(0, 1);
  lcd.setTextSize(1);
  lcd.setTextWrap(1);
  lcd.print("Craftycoder's");
  lcd.setCursor(1,15);
  lcd.print("Sharp Memory");
  lcd.setCursor(1,24);
  lcd.print("LCD Library"); 
  lcd.setCursor(1,33);
  lcd.print("Extends"); 
  lcd.setCursor(1,42);
  lcd.print("Adafruit GFX");  
  lcd.LcdPrintBuffer();
  delay(4000);
  lcd.LcdStopEXTC();
  lcd.LcdAllClearMode();
  lcd.LcdStartEXTC();
  lcd.drawLine(0, 0, 95, 95, 0);
  lcd.fillRect(4, 4, 7, 7, 0);
  lcd.fillCircle(7, 7, 2, 1);
  lcd.LcdPrintBuffer();
  delay(1000);
  lcd.LcdClearBuffer();
  lcd.setCursor(1,2);
  lcd.print("Draw Vectors");
  for(int x=0;x<32;x=x+4) {
    lcd.drawRect(20-x/2, 30-x/2, x, x, 0);
    lcd.drawCircle(73, 73, 20-x, 0);
    lcd.LcdPrintBuffer();
    delay(10);
  }
  delay(5000);
  lcd.invert(1);
  lcd.setCursor(1,11);
  lcd.print("Invert Them");  
  lcd.LcdPrintBuffer();
  delay(5000);  
  lcd.invert(0);
  lcd.LcdStopEXTC();
  lcd.LcdAllClearMode();
  lcd.LcdStartEXTC();
  lcd.setCursor(4,5);
  lcd.print("Reflow Oven");
  lcd.setCursor(4,14);
  lcd.print("Simulation");
  lcd.drawRect(0, 0, 96, 96, 0);
  lcd.drawRect(1, 1, 94, 94, 0);
  lcd.drawRect(2, 2, 92, 92, 0);
  for(int x=3;x<93;x++) {
    lcd.drawPixel(x,95-testTemp(x),0);
    lcd.drawPixel(x,96-testTemp(x),0);
    lcd.LcdPrintBuffer();
    delay(10);
  }
  lcd.setCursor(26,80);
  lcd.print("Remove PCBs");
  lcd.LcdPrintBuffer();
  delay(10000);
  lcd.invert(0);
  lcd.LcdStopEXTC();
  lcd.LcdAllClearMode();
  lcd.LcdStartEXTC();
}
int testTemp(int x) {
  if(x<30)
    return x+1;
  if(x<60)
    return 30+((x-30)/2);
  if(x<75)
    return 45+((x-60)*2); 
  if(x<85)   
    return 75;
  if(x<94)
    return 75-((x-85)*3);    
  
}
