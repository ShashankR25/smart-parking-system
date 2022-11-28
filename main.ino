#include <Wire.h>  
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F,16,2); //Change the HEX address #include <Servo.h> 
#include <ArduinoJson.h> 
Servo myservo1; 
String str; 
int Entry = 2; 
int Exit = 4; 
int IR1 = 5; 
int IR2 = 6; 
int IR3 = 7; 
int IR4 = 8; 
int Slot = 4; //Enter Total number of parking Slots 
int flag1 = 0; 
int flag2 = 0; 
void setup() { 
 // put your setup code here, to run once: 
 lcd.init(); 
 lcd.backlight(); 
 pinMode(Entry, INPUT);
DEPARTMENT OF COMPUTER SCIENCE, BCA[IoT] PAGE 18 
SMART PARKING SYSTEM National College Jayanagar 
 pinMode(Exit, INPUT); 
 pinMode(IR1, INPUT); 
 pinMode(IR2, INPUT); 
 pinMode(IR3, INPUT); 
 pinMode(IR4, INPUT); 
 pinMode(13, OUTPUT); 
  
 myservo1.attach(3); 
 myservo1.write(180); 
  
 lcd.setCursor (0,0); 
 lcd.print(" SMART "); 
 lcd.setCursor (0,1); 
 lcd.print(" PARKING SYSTEM "); 
 Serial.begin(9600); 
 delay (2000); 
 lcd.clear();  
} 
void loop() { 
 // put your main code here, to run repeatedly:  StaticJsonBuffer<1000> jsonBuffer; 
 JsonObject& root = jsonBuffer.createObject();   
 if(digitalRead (Entry) == LOW && flag1==0){  if(Slot>0)  
 {flag1=1; 
 if(flag2==0){myservo1.write(80); Slot = Slot-1;}  }else{ 
 lcd.setCursor (0,0);
DEPARTMENT OF COMPUTER SCIENCE, BCA[IoT] PAGE 19 
SMART PARKING SYSTEM National College Jayanagar 
 lcd.print(" SORRY :( ");  
 lcd.setCursor (0,1); 
 lcd.print(" Parking Full ");  
 delay (3000); 
 lcd.clear();  
 } 
} 
if(digitalRead (Exit) == LOW && flag2==0) 
{ 
 flag2=1; 
if(flag1==0){myservo1.write(80); Slot = Slot+1;} 
} 
if(flag1==1 && flag2==1){ 
delay (1000); 
myservo1.write(180); 
flag1=0, flag2=0; 
} 
int slot1 = digitalRead (IR1); 
int slot2 = digitalRead (IR2); 
int slot3 = digitalRead (IR3); 
int slot4 = digitalRead (IR4); 
if ((digitalRead (IR1) == LOW)||(digitalRead (IR2) == LOW)||(digitalRead (IR3) ==  LOW)|| (digitalRead (IR4) ==LOW)){ 
 digitalWrite(13, HIGH); 
} else { 
 digitalWrite(13, LOW); 
}

root["data1"] = slot1; 
 root["data2"] = slot2; 
 root["data3"] = slot3; 
 root["data4"] = slot4; 
 root.printTo(Serial); 
lcd.setCursor (0,0); 
lcd.print(" WELCOME! "); 
lcd.setCursor (0,1); 
lcd.print("Slot Left: "); 
lcd.print(Slot); 
delay(500); 
} 
