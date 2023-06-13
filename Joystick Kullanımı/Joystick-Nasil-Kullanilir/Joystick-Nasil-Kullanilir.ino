/*
*   Joystick Nasıl Kullanılır ?
*
*  Yazar: dezarto
*  Tarih: 13.06.2023
*/
// Bağlantı şekline göre gerekli pinler tanımlanır
int xPin = A4; 
int yPin = A3; 
int butonPin = 3; 
 
int xPozisyon;
int yPozisyon;
int butonDurum;
 
void setup() {
Serial.begin(9600);  // Seri haberleşme için tanımlanır
pinMode(xPin, INPUT);  // pinlerin INPUT girişli olduğu tanımlanır
pinMode(yPin, INPUT);
pinMode(butonPin, INPUT_PULLUP);
}
 
void loop() {
xPozisyon = analogRead(xPin);  // analogRead ile pinden değer okuması gerçekleştirilir
yPozisyon = analogRead(yPin);
butonDurum = digitalRead(butonPin);
 
Serial.print("X Pozisyonu: ");
Serial.print(xPozisyon);
Serial.print(" | Y Pozisyonu: ");
Serial.print(yPozisyon);
Serial.print(" | Buton Durum: ");
Serial.println(butonDurum);
delay(100);
}