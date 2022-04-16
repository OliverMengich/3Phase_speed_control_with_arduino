int delayTime = 0;
int sensor_pot = A0;
int currSensor3_pot = A4;
int voltage_sensor_pot = A5;
int sensor_value=0;
float current_value=0;
bool pressed = false;
bool started = false;
int button = 0;

int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double currentValue = 0;

#include <LiquidCrystal.h>
#define RS 13
#define EN 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void start_motor();
void stop_motor();
uint32_t calculate_voltage_value();
uint16_t get_max();
void take_Current_Value();
void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  pinMode(currSensor3_pot,INPUT);
  pinMode(sensor_pot,INPUT);
  pinMode(button, INPUT_PULLUP);
  
  lcd.begin(16, 2);
   //Print a message to the LCD.
  
  lcd.setCursor(0,0);
  lcd.print("SMART ENERGY METER");
  delay(500);
  
}
//void loop(){
//   start_motor();
//}
void loop(){
  // if LOAD is not started. Press the the start button
  if(started == false){
    lcd.print("Press Start Button");
   }
   //listening for the start button pressed
   if(digitalRead(button) == HIGH){
     lcd.setCursor(0, 0);
     lcd.print("Boot Button pressed");
     delay(1000);
     lcd.clear();
     pressed = !pressed;
     started = !started;
     if(pressed == true) {lcd.setCursor(0, 1); lcd.print("Motor ON"); delay(1000); lcd.clear(); } // if start button pressed display on the LED that it is on
     if(pressed ==false) {lcd.setCursor(0, 1); lcd.print("Motor Off"); delay(1000); lcd.clear(); } // if stop button pressed display on the LED that it is ff
   }
   while(digitalRead(button) == HIGH);
   delay(20);
   // starts the motor
   if(pressed == true){
     //start the motor WRITE A HIGH TO THE PINS
      start_motor();
   }
   // stop the motor
   if(pressed == false){
     // stop the motor. WRITE A LOW TO ALL THE PINS
     stop_motor();
   }
}

void start_motor() {
  // put your main code here, to run repeatedly:
  sensor_value = analogRead(sensor_pot);
  delayTime = map(sensor_value,0,1023,0,255);
  
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
  
  //take_Current_Value();
}
void stop_motor(){
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
void take_Current_Value(){
   
   float sensor3_value = analogRead(currSensor3_pot);
   float adcVoltage = (sensor3_value / 1024.0) * 5000;
   currentValue = ((offsetVoltage - adcVoltage) / sensitivity);
   float voltage_value = analogRead(voltage_sensor_pot);;
   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("SMART ENERGY METER");
   lcd.setCursor(0,1);
   lcd.print(currentValue);
   lcd.print("A ");
   lcd.print(voltage_value);
   lcd.print("V");
   delay(1000);
}
