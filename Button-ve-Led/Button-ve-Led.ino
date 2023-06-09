/*
Bu projede butona basıldığı zaman ledlerin yanması programlanmıştır.
Tarih: 09.06.2023
Yazar: dezarto
*/

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int defaultLed = 13;
int buttonPin = 8;
int state;

void setup() {
  pinMode(buttonPin, INPUT);

  pinMode(defaultLed, OUTPUT);  // default led
  pinMode(led1, OUTPUT);        // tek tek girişler tanımlanır
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {

  state = digitalRead(buttonPin);

  if (state) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(defaultLed, HIGH);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(defaultLed, LOW);
  }
}