int delayTime = 10;
int sensor_pot=A0;
int sensor_value=0;
//#include <LiquidCrystal.h>
//
//// initialize the library by associating any needed LCD interface pin
//// with the arduino pin number it is connected to
//const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Adafruit_ILI9341.h>
#define TFT_CS    8      // TFT CS  pin is connected to arduino pin 8
#define TFT_RST   9      // TFT RST pin is connected to arduino pin 9
#define TFT_DC    10     // TFT DC  pin is connected to arduino pin 10
// initialize ILI9341 TFT library
int delayTime = 10;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(sensor_pot,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  tft.begin();
  // Print a message to the LCD.
  delay(500);
  textToPrint();
}

void loop() {
  // put your main code here, to run repeatedly:
  //sensor_value = analogRead(sensor_pot);
  //delayTime = map(sensor_value,0,1023,0,255);
  
  lcd.setCursor(0,1);
  lcd.clear();
  lcd.print(delayTime);
  lcd.print("%");
  //1 5 6
  digitalWrite(1,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
   digitalWrite(4,LOW);
  delay(delayTime);
  //1,2,6
  digitalWrite(1,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(5, LOW);
  delay(delayTime);
  //1 ,2 ,3
  digitalWrite(1,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(6,LOW);
  delay(delayTime);
  //2, 3 4
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(1,LOW);
  delay(delayTime);
  // 3, 4,5
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(2,LOW);
  delay(delayTime);
  // 4 ,5 6
  digitalWrite(4,HIGH);
   digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(3,LOW);
  delay(delayTime);
}
unsigned long textToPrint(){
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.println("Done printing");
  return micros() - start;
}
