#include <FirebaseESP8266.h> 
#include <ESP8266WiFi.h> 
#include <ArduinoJson.h> 
FirebaseData fbda; 
int slot1 = 1; 
 int slot2 = 1; 
 int slot3 = 1; 
 int slot4 = 1; 
void setup() { 
 Serial.begin(9600); 
 WiFi.begin("HOME", "9353552385");  Serial.println("Connecting to HOME");  while (WiFi.status() != WL_CONNECTED)

 { 
 Serial.print("..."); 
 delay(500); 
 } 
 Serial.println("Connected"); 
 Firebase.begin("https://smart-parking-system-a968d-default-rtdb.firebaseio.com/",  "aqq7XGu5JsmltvSWbdsy6ZNIvpw5VgtMLU9hfzc4"); 
} 
void loop() { 
 StaticJsonBuffer<1000> jsonBuffer; 
 JsonObject& root = jsonBuffer.parseObject(Serial); 
  
 if(root == JsonObject::invalid()) 
 return; 
// Serial.println("JSON RECUVE"); 
// root.prettyPrintTo(Serial); 
 Serial.print("Data 1 ");  
 slot1 = root["data1"]; 
 Serial.println(slot1); 
 Serial.print("Data 2 "); 
 slot2 = root["data2"]; 
 Serial.println(slot2); 
 Serial.print("Data 3 ");  
 slot3 = root["data3"]; 
 Serial.println(slot3); 
 Serial.print("Data 4 "); 
 slot4 = root["data4"]; 
 Serial.println(slot2);
 
  
 Firebase.setInt(fbda,"SlotBooking/slot1",slot1);  Firebase.setInt(fbda,"SlotBooking/slot2",slot2);  Firebase.setInt(fbda,"SlotBooking/slot3",slot3);  Firebase.setInt(fbda,"SlotBooking/slot4",slot4); 
 }
