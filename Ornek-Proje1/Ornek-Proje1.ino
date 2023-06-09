/*
* Örnek 1 - Ledler ile Eğlence
* Kullanılacak Komponentler:
*   Breadboard üzerine 5 farklı renkte led bağlayın.
* Uygulamalar:
*   A - Tüm ledleri aynı anda yakıp söndürün
*   B - Ledleri sıra ile yakıp söndürün ( önce 1 sonra 2,3,4,5 ve geriye doğru 5,4,3,2,1) şeklinde.
*   C - Ledleri sıra sıra 10'ar kere yakıp söndürün ( önce 1. led 10 kere yanıp sönecek, sonra 2. led, sonra 3. led, ... sonra geriye doğru dön).
*
* Yazar: dezarto
* Tarih: 09.06.2023
*
*/

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  // Soru 1 Başlangıç
  /*
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);

  delay(1000);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);

  delay(1000);
  */
  // Soru 1 Bitiş

  // Soru 2 Başlangıç

  // 1. Yol Başlangıç
  /*
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED3, HIGH);
  delay(500);
  digitalWrite(LED4, HIGH);
  delay(500);
  digitalWrite(LED5, HIGH);

  delay(1000);

  digitalWrite(LED5, LOW);
  delay(500);
  digitalWrite(LED4, LOW);
  delay(500);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);
  digitalWrite(LED1, LOW);

  delay(1000);
  */
  // 1. Yol Bitiş
  // 2. Yol Başlangıç
  /*
  for (int i = 2; i <= 6; i++) {
    digitalWrite(i, HIGH);
    delay(50);
  }
  
  for (int i = 6; i >= 2; i--) {
    digitalWrite(i, LOW);
    delay(50);
  }
  delay(50);
  */
  // 2. Yol Bitiş
  // Soru 2 Bitiş

  // Soru 3 Başlangıç
  for (int a = 2; a <= 6; a++) {
    for (int i = 0; i <= 10; i++) {
      digitalWrite(a, HIGH);
      delay(50);
      digitalWrite(a, LOW);
      delay(50);
    }
  }
  delay(100);
  for (int a = 6; a >= 2; a--) {
    for (int i = 0; i <= 10; i++) {
      digitalWrite(a, HIGH);
      delay(50);
      digitalWrite(a, LOW);
      delay(50);
    }
  }
  // Soru 3 Bitiş
}
