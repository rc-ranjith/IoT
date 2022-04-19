#include<dht.h>
int temp = 5;
dht d;
void setup() {

 pinMode (temp,INPUT);
 Serial.begin(9600);

}

void loop() {
  
d.read11(temp);
Serial.println("Temperature: ");
Serial.println(d.temperature);
Serial.println("Humidity: ");
Serial.println(d.humidity);

}
