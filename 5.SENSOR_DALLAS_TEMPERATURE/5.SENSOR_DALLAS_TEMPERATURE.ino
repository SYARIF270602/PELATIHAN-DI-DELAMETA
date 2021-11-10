#include <OneWire.h>
#include<DallasTemperature.h>

int  sensorsuhu=2;
OneWire oneWire(sensorsuhu);
DallasTemperature sensors(&oneWire);
int Buzzer=3;


void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(Buzzer,OUTPUT);
 
}
 

void loop() {
  
 sensors.requestTemperatures();
 float bacaSuhu=sensors.getTempCByIndex(0);

 //
 Serial.print("SUHU");
 Serial.print(bacaSuhu);
 Serial.print("C");
 Serial.println();

 //LOGIKA

 if (sensorsuhu>31){
  digitalWrite(Buzzer,HIGH);
  delay(200);
 
 }if (sensorsuhu<31){
 digitalWrite(Buzzer,LOW);
 delay(1000);

}
}
