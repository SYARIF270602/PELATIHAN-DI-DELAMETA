int PB_1=2;
int PB_2=3;


int R=5;




void setup() {
 Serial.begin(9600);
 pinMode(PB_1,INPUT);
 pinMode(PB_2,INPUT);
 pinMode(R,OUTPUT);
 


 
}

void loop() {
  int bacaPB_1=digitalRead(PB_1);
  int bacaPB_2=digitalRead(PB_2);
 



if(bacaPB_1==1 and bacaPB_2==1){
  
  digitalWrite(R,HIGH);
  
 
}else{
digitalWrite(R,LOW);

}

}
