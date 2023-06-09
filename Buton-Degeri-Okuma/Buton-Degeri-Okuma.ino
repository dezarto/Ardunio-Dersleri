/*
Burada bir butona basıldığı zaman seri monitör üzerinden 
okunan değerin (1 veya 0) ekrana yazdırılması işlenmiştir.

Tarih: 09.06.2023
Yazar: dezarto
*/

int pinButton = 8;
int state;

void setup() {
  pinMode(pinButton, INPUT);

  Serial.begin(9600);
}

void loop() {
  state = digitalRead(pinButton);  // digitalRead() okuma işlemi yapmamızı sağlıyor.

  Serial.println(state);

}
