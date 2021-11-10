#include<Servo.h>
#include<SPI.h>
#include<MFRC522.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
String uidString;

//INISIALISASI
int outServo=6;
int buzzer=3;
int sensorIR=5;
int kunci=0;
Servo myservo;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522 (SS_PIN,RST_PIN);

void setup() {
  Serial.begin(9600);
  myservo.attach(outServo);
  lcd.begin();
  pinMode(buzzer,OUTPUT);
  pinMode(sensorIR,INPUT);
  SPI.begin();//intiate SPI Bus
  mfrc522.PCD_Init();
  bunyibuzzeroke();

  
  
}

void loop() {
  int bacaIR=digitalRead(sensorIR);

 if(mfrc522.PICC_IsNewCardPresent() and kunci==0) {
  readRFID();
  Serial.print("TAG UID:");
  Serial.println(uidString);
  if(uidString=="74-81-110-174"){
    kunci=1;
   lcd.clear();
  lcd.setCursor(1,0); lcd.print("PALANG TERBUKA");
  Serial.println("BERHASIL");
   myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  bunyibuzzeroke();
 }else{
  lcd.clear();
  lcd.setCursor(5,1); lcd.print("GAGAL");
  delay(500);
  Serial.println("GAGAL");
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
  bunyibuzzergagal();
  
 }
}
//LOGIKA
if (bacaIR==0 and kunci==1){
lcd.clear();
lcd.setCursor(1,1); lcd.print("PALANG DITUTUP");
Serial.print("PALANG DITUTUP");
 myservo.write(90);
  delay(1000);
  myservo.write(0);
delay(1000);
Serial.println();
lcd.clear();
lcd.setCursor(1,0); lcd.print("SELAMAT DATANG");
Serial.print("SELAMAT DATANG");
delay(1000);
lcd.clear();
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");

kunci=0;
}
}

void readRFID() {
  mfrc522.PICC_ReadCardSerial();
 
  //Pembatas bisa dirubah sesuai keinginan,disini yang digunakan "-"
  uidString=String(mfrc522.uid.uidByte[0]) + "-" +
            String(mfrc522.uid.uidByte[1]) + "-" +
            String(mfrc522.uid.uidByte[2]) + "-" +
            String(mfrc522.uid.uidByte[3]);
}

void bunyibuzzeroke(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  
  
}

void bunyibuzzergagal(){
  digitalWrite(buzzer,HIGH);
  delay(600);
  digitalWrite(buzzer,LOW);
}
