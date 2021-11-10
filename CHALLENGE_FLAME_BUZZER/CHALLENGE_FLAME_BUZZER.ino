int pinLDR=A0;
int sensorFlame=A1;
int pinR=5;
int pinY=6;
int pinG=7;
int Buzzer=3;


void setup() {
  Serial.begin(9600);
  pinMode(pinR,OUTPUT);
  pinMode(pinY,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(sensorFlame,INPUT);
  pinMode(Buzzer,OUTPUT);
  
 
}

void loop() {
  //BACA DATA
  int bacaLDR=analogRead(pinLDR);
  int bacaFlame=analogRead(sensorFlame);
  int bacaBuzzer=analogRead(Buzzer);
   bacaFlame=map(bacaFlame,25,1018,100,0);
   bacaLDR=map(bacaLDR,25,1018,0,100);
   
  
  //print serial
  Serial.print("NILAI LDR;");
  Serial.print(bacaLDR);
  Serial.print("NILAI FLAME:");
  Serial.print(bacaFlame);
  Serial.println();
  delay(100);

  //LOGIKA
  analogWrite(pinR,bacaLDR);
  if (bacaFlame<25){
   digitalWrite(pinG,HIGH);
     digitalWrite(pinY,LOW); 
  digitalWrite(Buzzer,LOW);
  delay(100);
  Serial.println("AMAN BANGET");
  
  
  } 
    else if (bacaFlame>25 and bacaFlame<35){
    digitalWrite(pinY,HIGH);
    digitalWrite(pinG,LOW);
    digitalWrite(Buzzer,HIGH);
    delay(500);
    digitalWrite(Buzzer,LOW);
    delay(500);
    Serial.println("WARNING SILAHKAN PERIKSA");
  
    
  }
  else{
    digitalWrite(pinY,HIGH);
    digitalWrite(pinG,HIGH);
    digitalWrite(Buzzer,HIGH);
    delay(200);
    digitalWrite(Buzzer,LOW);
    delay(200);
    Serial.println("WASPADA HARAP MENGUNGSI");
   
   
  }
 
  

 
}
