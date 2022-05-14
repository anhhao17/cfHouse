#include <Arduino.h>
#include <WebServer.h>
#include "EEPROM.h"
#include "WiFi.h"
#include "connectWiFi.h"

 
void setup() {
  Serial.begin(115200);
  WiFi.disconnect();
  delay(1000);
  EEPROM.begin(64);
  
  char ssid[32];
  char pass[32];
  Serial.println("READING EEPROM SSID");
  if(EEPROM.read(0)!=0){
    strcpy(ssid,EEPROM.readString(0).c_str());
    strcpy(pass,EEPROM.readString(32).c_str());
  }
   
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pass);
  delay(1000);
  if(WiFi.waitForConnectResult()==WL_CONNECTED){
    Serial.println("CONNECTED");
  }
  else{
    Serial.println("SETUPap");
    setupAP();
  }

  Serial.println();
  Serial.println("Waiting.");
  
  while ((WiFi.status() != WL_CONNECTED))
  {
    Serial.print(".");
    delay(100);
    server.handleClient();
  }  


}

void loop() {
  // put your main code here, to run repeatedly:
}




