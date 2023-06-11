//NRF24L01 alıcı kodu
//Mucit Pilot
//Ağustos 2020
//mucitpilot.blogspot.com

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

#define KEY1 0  //diziden gelecek değişkenler için tanımladık (bu örnekte 2 veri alacağız)
#define KEY2 0


/*-----( kütüphaneleri yükleyelim )-----*/
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//RF modülün pinleri
#define CE_PIN 8
#define CSN_PIN 9


const uint64_t pipe = 0xE8E8F0F0E1LL;  // adres


/*-----( radio nesnesi yaratılıyor)-----*/
RF24 radio(CE_PIN, CSN_PIN);  //
/*-----( değişkenler tanımlanıyor )-----*/

// radiodan gelen 5 adet veriyi almak için bir dizi oluşturuyoruz
int verilerim[] = { KEY1, KEY2 };  // keylerimiz
int servodegeri, leddegeri;
Servo servoNesnesi;  //servomuz için bir nesne tanımladık.

int led = 2;  //ledi Arduino'nun 2.pinine
//Bu ledi kumanda ile iletişim kurma başarılı ise yakıp kumandayı görmüyorsa söndürüyoruz

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(led, OUTPUT);
  servoNesnesi.attach(A3);  //servomuzun sinyal kablosu 10. pwm kanala bağlı
  //////////////////////////////////////////////////////////

  //radio ile iletişim kuruyoruz
  Serial.println("Nrf24L01 Alıcı Başlatılıyor");
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  ///////////////////////////////
}  //--(setup bitti )---


void loop() /****** LOOP: sürekli çalışır ******/
{

  if (radio.available())  //eğer radyo ile temas kurabilmişse
  {
    // done değişkeni false yapıyoruz ve while içinde sonsuz döngü oluşturarak verileri toplayacağız
    bool done = false;
    while (!done) {
      // veriyi alıyoruz.
      //done = radio.read(verilerim, sizeof(verilerim));   //ne kadar veri varsa al demek
      done = radio.available();
      if (done) {
        radio.read(verilerim, sizeof(verilerim));
      }

      digitalWrite(led, LOW);                            //ledi söndürdük
      servodegeri = map(verilerim[0], 0, 1023, 0, 179);  //stickten gelen bilgiyi servo için 0-179 aralığına uyarladık
      leddegeri = map(verilerim[1], 0, 1023, 0, 255);    //stickten gelen bilgiyi 0-255 aralığına uyarladık
      //serial monitörden verileri görmek için;
      Serial.print("KEY1 = ");
      Serial.print(servodegeri);
      Serial.print("   KEY2 = ");
      Serial.print(leddegeri);
      Serial.println();

      // kumandadan gelen değerlere göre hareketlere karar veriyoruz (burada her joystick için yaklaşık orta noktaya göre +-10 birim nötr alan bırakmak gerek
      //ki parazitten değişince istemsiz hareket etmesin

      servoNesnesi.write(servodegeri);

      if ((leddegeri > 130) || (leddegeri < 120))  // sadece ileri komutu veriliyor ileri gidecek
      {
        digitalWrite(led, HIGH);
      } else {
        digitalWrite(led, LOW);
      }



    }  //while
  }    //ilk if

  //eğer radyo bulunamazsa
  else {
    Serial.println("Verici Bulunamadı");
    verilerim[0] = 0;
    verilerim[1] = 0;

    servoNesnesi.write(90);  //servoyu ortalıyoruz
    digitalWrite(led, LOW);  //ledimizi de söndürüyoruz
  }

}  //--(main loop sonu )---