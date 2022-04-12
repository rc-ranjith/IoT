#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
const char* ssid = "Ranjith";
const char* password = "password";

WiFiClient client;
long myChannelNumber = 1695339;
char myWriteAPIKey[] = "CEK14HA8GBOF74T7";

int write_val = 50;
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
  // put your main code here, to run repeatedly:
  int status = ThingSpeak.writeField(myChannelNumber,1,write_val,myWriteAPIKey);
  if (status == TS_OK_SUCCESS) {
    Serial.println("Write Success");
    write_val = write_val + 1;
  }
  delay(2000);
}
