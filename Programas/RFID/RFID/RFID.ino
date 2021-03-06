
/*
//Programa: Sistema de trava eletrica com RFID
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 53
#define RST_PIN 5
int electronic_lock = 12;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
  pinMode(2, OUTPUT);
}
 
void loop() 
{
  // Procura por cartao RFID
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Seleciona o cartao RFID
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
 
  if (conteudo.substring(1) == "27 9B 01 3C") //UID 1 - Cartao
  {
    Serial.println("Ola FILIPEFLOP !");
    Serial.println();
    digitalWrite(electronic_lock, HIGH);
    delay(3000);           // espera 3 segundos
    digitalWrite(electronic_lock, LOW);
    Serial.println("Unlocked"); 
  }  

  if (conteudo.substring(1) == "2B 82 22 1B") //UID 1 - Cartao
  {
    Serial.println("Ola ines !");
    Serial.println();
    digitalWrite(12, HIGH); // ativa rele, abre a trava solenoide
    delay(3000);           // espera 3 segundos
    digitalWrite(12, LOW);  // desativa rele, fecha a trava solenoide
  }
  
}*/
//Programa: Sistema de trava eletrica com RFID
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
  pinMode(2, OUTPUT);
}
 
void loop() 
{
  // Procura por cartao RFID
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Seleciona o cartao RFID
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
 
  if (conteudo.substring(1) == "27 9B 01 3C") //UID 1 - Cartao
  {
    Serial.println("Ola FILIPEFLOP !");
    Serial.println();
    digitalWrite(2, HIGH); // ativa rele, abre a trava solenoide
    delay(3000);           // espera 3 segundos
    digitalWrite(2, LOW);  // desativa rele, fecha a trava solenoide
  }  
}
