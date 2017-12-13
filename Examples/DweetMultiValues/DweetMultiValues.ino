#include "dweetESP8266.h"
#define THIG_NAME  "Your_thing_neme_here"  // Put here your thing name
#define WIFISSID "ssid"
#define PASSWORD "password"
#define KEY1 "analog0"
#define KEY2 "analog2"
#define KEY3 "analog3"

dweet client;

void setup(){
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
}
void loop(){
    String value1 = String(analogRead(A0));
    String value2 = String(analogRead(A1));
    String value3 = String(analogRead(A2));
    client.add(KEY1, value1); // specifies the args of type "String"
    client.add(KEY2, value2);
    client.add(KEY3, value3);
    client.sendAll(THIG_NAME);
}
