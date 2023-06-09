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

  pinMode(led1, OUTPUT);  // tek tek girişler tanımlanır
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  digitalWrite(defaultLed, HIGH);

  digitalWrite(led1, HIGH);  // ledlerin yanmasını sağlar
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);

  delay(1000);  // 1 saniye bekletir

  digitalWrite(13, LOW);

  digitalWrite(led1, LOW);  // ledlerin sönmesini sağlar
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  delay(1000);
}