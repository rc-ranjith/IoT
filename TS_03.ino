#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include<dht.h>
const char* ssid = "Ranjith";
const char* password = "password";
int temp = 5;
dht d;

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
  pinMode (temp,INPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Humidity & temperature sensor \n\n");
  delay(1000);

  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  d.read11(temp);
  int temp = d.temperature;
  int status = ThingSpeak.writeField(myChannelNumber,1,temp,myWriteAPIKey);
  if (status == TS_OK_SUCCESS) {
    Serial.println("Write Success");
  delay(2000);
}
}
