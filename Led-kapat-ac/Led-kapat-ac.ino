int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

void setup() {
  pinMode(13, OUTPUT);

  pinMode(2, led1);  // tek tek girişler tanımlanır
  pinMode(3, led2);
  pinMode(4, led3);
  pinMode(5, led4);
}

void loop() {
  digitalWrite(5, led1);   // ledlerin yanmasını sağlar
  digitalWrite(2, led2);
  digitalWrite(3, led3);
  digitalWrite(4, led4);
  digitalWrite(13, HIGH);
  delay(1000);  // 1 saniye bekletir

  digitalWrite(5, LOW);  // ledlerin sönmesini sağlar
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(13, LOW);
  delay(1000);
}
