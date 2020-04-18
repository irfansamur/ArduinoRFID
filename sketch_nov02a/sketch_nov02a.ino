#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  
 
void setup() 
{
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init();  
  Serial.println("KARTINI OKUT");
  Serial.println();
  pinMode(8,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
}
void loop() 
{
  digitalWrite(2,HIGH);
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID ETİKETİ:");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("MESAJ : ");
  content.toUpperCase();
  if (content.substring(1) == "A0 5F D5 83") 
  {
    Serial.println("ERİŞİME İZİN VERİLDİ");
    Serial.println();
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
  }
 
 else   {
    Serial.println("ERİŞİM REDDEDİLDİ");
     digitalWrite(2,LOW);
    delay(500);
    digitalWrite(2,HIGH);
  }
} 
