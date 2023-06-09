/*
Bu projede potansiyometre den değer alma ve voltage hesaplama
gibi basit işlemleri gerçekleştirmektedir.
Tarih: 09.06.2023
Yazar: dezarto
*/
int value;
float voltage = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);  // A0 girişinden analog değerleri okuruz
  Serial.print("value = ");
  Serial.print(value);

  voltage = value * (5000.0 / 1023);  // 2^10 = 1024, 5 volt 5000 mini volt yapar,
                                      // 5000 / 1024 = 4,88 milivolt hassasiyet ile 
                                      // analog veri okuma gerçekleştirilir.
  Serial.print("   voltage = ");
  Serial.println(voltage);
}
