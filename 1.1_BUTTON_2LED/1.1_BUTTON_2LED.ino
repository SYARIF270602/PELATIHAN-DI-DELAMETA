int PB_1=2;



int R=5;
int Y=6;




void setup() {
 Serial.begin(9600);
 pinMode(PB_1,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 


 
}

void loop() {
  int bacaPB_1=digitalRead(PB_1);
  
 



if(bacaPB_1==1 ){
  
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
 
  
  
 
}else{
digitalWrite(R,LOW);
digitalWrite(Y,LOW);

}

}
