/*
Bu projede analogWriter() kodu ile belirtmiş olduğumuz ledlerin
en düşük parlaklık seviyesinden en yüksek parlaklık seviyesine
arttırma işlemi gerçekleştirilmiştir. 

analogWriter 0-255'e kadar değerler alabilir.
0 - En düşük
255 - En yüksek değerdir

Çalışma mantığı PWM(Pulse With Modulation)'dir.

Tarih: 09.06.2023
Yazar: dezarto
*/
#define WHITELED 3
#define YELLOWLED 5

void setup() {
  pinMode(WHITELED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
}

void loop() {
  for (int i = 0; i < 256; i++) {
    analogWrite(WHITELED, i);
    analogWrite(YELLOWLED, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(WHITELED, i);
    analogWrite(YELLOWLED, i);
    delay(10);
  }
}
