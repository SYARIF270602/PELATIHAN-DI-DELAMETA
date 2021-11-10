int pinLDR=A0;
int pinR=5;


void setup() {
  Serial.begin(9600);
  pinMode(pinR,INPUT);
 
}

void loop() {
  //BACA DATA
  int bacaLDR=analogRead(pinLDR);
   bacaLDR=map(bacaLDR,25,1018,100,0);
  
  //print serial
  Serial.print("NILAI;");
  Serial.print(bacaLDR);
  Serial.println();

  //LOGIKA
  analogWrite(pinR,HIGH);

 
}
