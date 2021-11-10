int PB_1=2;
int sensorIR=3;



int R=5;
int Y=6;
int G=7;





void setup() {
 Serial.begin(9600);
 pinMode(PB_1,INPUT);
 pinMode(sensorIR,INPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
 


 
}

void loop() {
  //BACA DATA
  int bacaPB_1=digitalRead(PB_1);
  int bacaIR=digitalRead(sensorIR);
  

//PRINT SERIAL
Serial.print("Tombol: ");
Serial.print(bacaPB_1);
Serial.print(" | sensor IR: ");
Serial.print(bacaIR);
Serial.println(); //Untuk Enter
  
 
//LOGIKA
if(bacaPB_1==0 and bacaIR==0){
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  Serial.println("Tombol 1:" + String(bacaPB_1));

   sensorIR=1;
 
  
}




if(bacaPB_1==1 and bacaIR==1 ){
  
  digitalWrite(R,LOW);
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  Serial.println("Tombol 1:" + String(bacaPB_1));

   sensorIR=1; 
}
if(bacaPB_1==0 and bacaIR==1){
  digitalWrite(R,HIGH);
  Serial.println("Tombol 1:" + String(bacaPB_1));

 sensorIR=0;

  
  
 


}

}
