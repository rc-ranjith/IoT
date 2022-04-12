#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
const char* ssid = "Ranjith";
const char* password = "password";

WiFiClient client;
long myChannelNumber = 1695339;
char myReadAPIKey[] = "Q9NZ0CH0OCCAVCFN";
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
  int read_val = ThingSpeak.readIntField(myChannelNumber,1,myReadAPIKey);
  int status = ThingSpeak.getLastReadStatus();
  if (status == TS_OK_SUCCESS) {
    Serial.println(read_val);
  }
  else{
    Serial.println("Error in reading values");
  }
  delay(20000);
}
