//INISIALISASI
int pinPIR=2;
int pinBuzzer=3;

void setup() {
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(pinBuzzer,OUTPUT);

}

void loop() {
  // BACA SENSOR
  int bacaPIR=digitalRead(pinPIR);
  int bacaBuzzer=digitalRead(pinBuzzer);

  //PRINT TO SERIAL
  Serial.print("PIR:");
  Serial.print(bacaPIR);
  Serial.println();// UNTUK ENTER

  //LOGIKA
  if(bacaPIR==1){
    Serial.println("AWAS ADA MALING !!!");
    digitalWrite(pinBuzzer,HIGH);
    delay(100);
  }else{
    Serial.print("AMAN BOSSS QUE..");
    digitalWrite(pinBuzzer,LOW);
  }
  

}
