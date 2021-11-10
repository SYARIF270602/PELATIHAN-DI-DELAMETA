int PB_1=2;
int PB_2=3;
int PB_3=4;
int R=5;
int Y=6;
int G=7;
void setup() {
 Serial.begin(9600);
 pinMode(PB_1,INPUT);
 pinMode(PB_2,INPUT);
 pinMode(PB_3,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
}

void loop() {
  int bacaPB_1=digitalRead(PB_1);
  Serial.println("Kondisi tombol:" +String(bacaPB_1));
   int bacaPB_2=digitalRead(PB_2);
  Serial.println("Kondisi tombol:" +String(bacaPB_2));
   int bacaPB_3=digitalRead(PB_3);
  Serial.println("Kondisi tombol:" +String(bacaPB_3));
 

  if(PB_1==1){
    digitalWrite(R,HIGH);
    delay(100);
    //digitalWrite(R, LOW);
    //delay(100);
  }else{
     digitalWrite(R,LOW);
     delay(100);
  }
   if(PB_2==1){
    digitalWrite(Y,HIGH);
   }else{
    delay(100);
   digitalWrite(Y,LOW);
   delay(100);
   }
  if(PB_3==1){
    digitalWrite(G,HIGH);
  }else{
    delay(100);
  digitalWrite(G,LOW);
  }
 
}
