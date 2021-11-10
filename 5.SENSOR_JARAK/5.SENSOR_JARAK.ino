#include<NewPing.h>
int triger=5;
int echo=4;
int batas=200;
int Buzzer=3;
int R=6;
int Y=7;
int G=8;

NewPing cm(triger,echo,batas);
void setup() {
  Serial.begin(9600);
  pinMode(Buzzer,OUTPUT);
  pinMode(R,OUTPUT);
   pinMode(Y,OUTPUT);
    pinMode(G,OUTPUT);
  


}

void loop() {
  int bacaJarak=cm.ping_cm();
  

  //PRINT KE SERIAL
  Serial.print("DataJarak");
  Serial.print(bacaJarak);
  Serial.print("cm");
  Serial.println();

//LOGIKA

if (bacaJarak<20){
   digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
     digitalWrite(G,LOW);
  digitalWrite(Buzzer,HIGH);
  delay(200);
  Serial.println("BERHENTI:");
 
}else if (bacaJarak>21 and bacaJarak<70){
  digitalWrite(Buzzer,HIGH);
  delay(1000);
  digitalWrite(Y,HIGH);
   digitalWrite(R,LOW);
    digitalWrite(G,LOW);
  Serial.println("BAHAYA:");
}else{
digitalWrite(G,HIGH);
 digitalWrite(R,LOW); 
  digitalWrite(Y,LOW);
Serial.println("AMAN:");
  
}  
}
