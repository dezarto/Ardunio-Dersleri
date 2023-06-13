/*
* Servo Motor Nasıl Kullanılır ?
*
* Yazar: dezarto
* Tarih: 13.06.2023
*/

#include <Servo.h>

Servo servo1;         // servo motorumuzun ismini tanımlıyoruz
int aciDegeri = 179;  // örnek bir açı değeri tanımlıyoruz

void setup() {
  servo1.attach(A5);  // Servo motorumuzun Veri Pinini bağladığımız pin numarasını yazıyoruz
                      // bu fonksiyon sayesinde pini tanımlamış olduk
}

void loop() {
  //servo1.write(aciDegeri);  // Servo motorumuzun dönmesini istedğimiz acıDegerini yazıyoruz

  for (int i = 0; i < 180; i++) {
    servo1.write(i);
    delay(10);
  }
  delay(1000);
  for (int i = 179; i >= 0; i--) {
    servo1.write(i);
    delay(10);
  }
  delay(1000);
}
