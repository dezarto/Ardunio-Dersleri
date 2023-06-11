//NRF Verici Kodu
//Mucit Pilot 
//mucitpilot.blogspot.com
//Ağustos 2020 
/*
nRF24L01 Modül Bağlantıları:
   1 - GND
   2 - VCC 3.3V !!! 5V DEĞİL !!!
   3 - CE Arduino pin 9
   4 - CSN Arduino pin 8
   5 - SCK Arduino pin 13
   6 - MOSI Arduino pin 11
   7 - MISO Arduino pin 12
   8 - Kullanmıyoruz
   -
   Analog Joystick veya 10K pot:
   GND --Arduino GND
   VCC -- Arduino +5V
   X Pot -- Arduino A0
   Y Pot -- Arduino A1

 */
/*-----( Gerekli Kütüphaneleri Yüklüyoruz )-----*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Değişkenlerimizi tanımlıyoruz )-----*/
#define CE_PIN   8
#define CSN_PIN 9
#define YEKSEN A1
#define XEKSEN A0

// NOT: Sondaki "LL" "LongLong" tipi demek
const uint64_t pipe = 0xE8E8F0F0E1LL; // yayın adresi diyebiliriz iki tarafta da aynı olmalı ki haberleşebilsinler (transmit pipe deniyor)
 
 
/*-----( RF24 kütüphanesi ile radio adında bir haberleşme nesnesi yaratıyoruz )-----*/
RF24 radio(CE_PIN, CSN_PIN); // radio yaratıldı
/*-----( Girdileri tutacağımız diziyi tanımlayalım )-----*/
int verilerim[2]; // 
 
void setup()   /****** SETUP: 1 defa çalışır ******/
{
  Serial.begin(9600); 
  radio.begin(); //iletişimi başlattık
  //kumandadaki pinleri tanımlıyoruz
  pinMode(YEKSEN, INPUT);
  pinMode(XEKSEN, INPUT);

  radio.openWritingPipe(pipe); //adrese bağlanıyoruz
}//--(setup kısmı bitimi )---
 
 
void loop()   /****** LOOP: sürekli çalışıyor ******/
{

  verilerim[0]=analogRead(A0); //kumandadan verileri okuyup dizimize yazdırıyoruz
  verilerim[1]=analogRead(A1);

  radio.write( verilerim, sizeof(verilerim) ); //verileri gönderilmek üzere çıkışa yazdırıyoruz
 
}// loop sonu
 
//
//BİTTİ