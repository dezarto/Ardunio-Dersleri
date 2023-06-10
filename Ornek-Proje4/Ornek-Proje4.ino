/*
*   Örnek 4 - Potansiyometre İle Led Kontrolü
*   Kullanılacak Komponentler:
*     Breadboard üzerine 1 tane pot 1 tane led bağlayın (PWM)
*   Uygulama:
*     Potansiyometreden gelen değerlere göre ledin parlaklığını kontrol eden bir uygulama geliştirin.
*
*   Yazar: dezarto
*   Tarih: 10.06.2023
*/

int value;

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);
  Serial.print("Value = ");
  Serial.print(value);
  //value /= 4;  // Led değeri 0 ile 255 arasında alır
  value = map(value, 0, 1023, 0, 255); // 0 ile 1023 değerini 0 ile 255 e oranlar
  Serial.print("    Value = ");
  Serial.println(value);

  analogWrite(3, value);
}
