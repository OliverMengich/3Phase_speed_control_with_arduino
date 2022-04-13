int delayTime = 0;
int sensor_pot = A0;
int currSensor1_pot = A2;
int currSensor2_pot = A3;
int currSensor3_pot = A4;
int voltage_sensor_pot = A5;
int sensor_value=0;
float current_value=0;
bool pressed = false;
int button = 0;
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
void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  //pinMode(currSensor1_pot,INPUT);
  pinMode(currSensor2_pot,INPUT);
  pinMode(currSensor3_pot,INPUT);
  pinMode(sensor_pot,INPUT);
  pinMode(button, INPUT_PULLUP);
  
  lcd.begin(16, 2);
   //Print a message to the LCD.
  
  lcd.setCursor(0,0);
  lcd.print("Smart Energy Meter");
  delay(500);
  
}
void loop(){
   start_motor();
}
//void loop(){
//   if(digitalRead(button) == HIGH){
//     tft.setCursor(0, 4);
//     tft.setTextSize(1);
//     tft.println("Boot Button pressed");
//     
//     pressed = !pressed;
//     tft.println(pressed);
//   }
//   while(digitalRead(button) == HIGH);
//   delay(20);
//   if(pressed == true){
//     //start the motor WRITE A HIGH TO THE PINS
//      tft.setTextSize(1);
//      tft.println("Motor on");
//      start_motor();
//   }
//   if(pressed == false){
//     // stop the motor. WRITE A LOW TO ALL THE PINS
//     tft.setTextSize(1);
//     tft.println("Motor Off");
//     stop_motor();
//   }
//}

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

  take_Current_Value();
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
   float sensor1_value = analogRead(currSensor1_pot);
   float sensor2_value = analogRead(currSensor2_pot);
   float sensor3_value = analogRead(currSensor3_pot);
   float voltage_value = analogRead(voltage_sensor_pot);
   float average_value = (sensor1_value + sensor2_value + sensor3_value)/3 ;
   lcd.clear();
   lcd.setCursor(0,1);
   lcd.print(average_value);
   lcd.print("A ");
   lcd.print(voltage_value);
   lcd.print("V");
   
}
