#include<dht.h>
int temp = A0;
dht a;
void setup()
{
  pinMode(temp,INPUT);
  Serial.begin(9600);
}
void loop()
{
  a.read11(temp);
  delay (2000);
  //Serial.print("Temperature:");
  int temp = a.temperature;
  Serial.println(temp);
  //Serial.print("Humidity:");
  //Serial.println(a.humidity);
}
