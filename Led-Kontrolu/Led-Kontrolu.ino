/*
Bu kod satırında 4 farklı led 1 saniye aralıklarla sönüp yanmaktadır.
Tarih: 09.06.2023
Yazar: dezarto
*/

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int defaultLed = 13;

void setup() {
  pinMode(defaultLed, OUTPUT);  // default led

  pinMode(2, led1);  // tek tek girişler tanımlanır
  pinMode(3, led2);
  pinMode(4, led3);
  pinMode(5, led4);
}

void loop() {
  digitalWrite(defaultLed, HIGH);

  digitalWrite(5, led1);  // ledlerin yanmasını sağlar
  digitalWrite(2, led2);
  digitalWrite(3, led3);
  digitalWrite(4, led4);

  delay(1000);  // 1 saniye bekletir

  digitalWrite(13, LOW);

  digitalWrite(5, LOW);  // ledlerin sönmesini sağlar
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  delay(1000);
}