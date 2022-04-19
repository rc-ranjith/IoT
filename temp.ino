#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include<dht.h>
const char* ssid = "IoT";
const char* password = "password";

WiFiClient client;
long myChannelNumber = 1695339;
char myWriteAPIKey[] = "CEK14HA8GBOF74T7";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  Serial.print("Attempting to connect to SSID: ");
  Serial.print(ssid);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(5000);
  }
  Serial.println("");
  Serial.println("Wifi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}

void loop() { 
  if(Serial.available() > 0 )
  {
    int temp = Serial.read();
    Serial.print("Temperature: ");
    Serial.print(temp);
    int status = ThingSpeak.writeField(myChannelNumber,1,temp,myWriteAPIKey);
  if (status == TS_OK_SUCCESS) {
    Serial.println("Temperature Write Success!");
  }
  }
delay(20000);
}
