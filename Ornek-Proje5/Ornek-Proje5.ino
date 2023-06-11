/*
* Kullanılacak Komponentler:
*   1 tane Breadboard
*   7 tane Led
*   1 tane Buzzer
*   3 tane Button
*   10 tane Drienç
*   1 tane Potansiyometre
* Uygulama:
*   Button 1'e basıldığı zaman soldan sağa tüm ledler yanar ve ardından söner.
*   Button 2'ye basıldığı zaman soldan sağa doğru ledler yanar ancak bir kere yanan led ardından sönüp devam eder.
*   Button 3'e basıldığı zaman potansiyometre ile ledlerin parlaklığı kontrol edilir.
*   Her bir butona basıldığı zaman butonların yanındaki led bir defa yanıp söner ve bir defa buzzer ile bip sesi duyulur.
* Yazar: dezarto
* Donanım yardımcısı: lonely Wolf
* Tarih: 11.06.2023
*/

#define WHITE_LED 8
#define GREEN_LED 7
#define RED_LED 6
#define BLUE_LED 5
#define BUZZER 9
#define POTANSIYOMETER A0
#define RIGHT_WHITE_LED 2
#define RIGHT_BLUE_LED 3
#define RIGHT_YELLOW_LED 4
#define BUTTON1 12
#define BUTTON2 11
#define BUTTON3 10
#define DEFAULT_LED 13

void setup() {
  pinMode(DEFAULT_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RIGHT_WHITE_LED, OUTPUT);
  pinMode(RIGHT_BLUE_LED, OUTPUT);
  pinMode(RIGHT_YELLOW_LED, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

int state1, state2, state3, potansiyometre, open_close = 0;

void loop() {

  digitalWrite(DEFAULT_LED, HIGH);
  delay(100);
  digitalWrite(DEFAULT_LED, LOW);
  delay(100);

  state1 = digitalRead(BUTTON1);
  state2 = digitalRead(BUTTON2);
  state3 = digitalRead(BUTTON3);

  potansiyometre = analogRead(POTANSIYOMETER);
  potansiyometre = map(potansiyometre, 0, 1023, 0, 255);

  if (state1) {
    while (digitalRead(BUTTON1)) {
      delay(100);
    }
    digitalWrite(RIGHT_WHITE_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    open_close = !(open_close);

    for (int i = 8; i >= 5; i--) {
      digitalWrite(i, open_close);
    }

  } else if (state2 && !(open_close)) {
    while (digitalRead(BUTTON2)) {
      delay(100);
    }
    digitalWrite(RIGHT_BLUE_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    for (int i = 8; i >= 5; i--) {
      digitalWrite(i, HIGH);
      delay(500);
      digitalWrite(i, LOW);
      digitalWrite(BUZZER, LOW);
      digitalWrite(RIGHT_BLUE_LED, LOW);
    }

  } else if (state3 && !(open_close)) {
    while (digitalRead(BUTTON3)) {
      delay(100);
    }
    digitalWrite(RIGHT_YELLOW_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    for (int i = 8; i >= 5; i--) {
      digitalWrite(i, HIGH);
      delay(500);
      digitalWrite(BUZZER, LOW);
      digitalWrite(RIGHT_YELLOW_LED, LOW);
    }
    for (int i = 8; i >= 5; i--) {
      digitalWrite(i, LOW);
    }
  } else {
    digitalWrite(RIGHT_WHITE_LED, LOW);
    digitalWrite(RIGHT_YELLOW_LED, LOW);
    digitalWrite(RIGHT_BLUE_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  if (open_close) {
    analogWrite(WHITE_LED, potansiyometre);
    analogWrite(GREEN_LED, potansiyometre);
    analogWrite(RED_LED, potansiyometre);
    analogWrite(BLUE_LED, potansiyometre);
    //for (int i = 8; i >= 5; i--) {
    //digitalWrite(i, potansiyometre);
    //}
  }
  Serial.println(potansiyometre);

  /*
  Devrenin çalışıp çalışmadığı kontrolü

  state1 = digitalRead(BUTTON1);
  state2 = digitalRead(BUTTON2);
  state3 = digitalRead(BUTTON3);

  Serial.print("State1 = ");
  Serial.print(state1);
  Serial.print("  State2 = ");
  Serial.print(state2);
  Serial.print("  State3 = ");
  Serial.println(state3);

  digitalWrite(WHITE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);

  digitalWrite(RIGHT_WHITE_LED, HIGH);
  digitalWrite(RIGHT_BLUE_LED, HIGH);
  digitalWrite(RIGHT_YELLOW_LED, HIGH);

  digitalWrite(BUZZER, HIGH);
  

  potansiyometre = analogRead(POTANSIYOMETER);

  Serial.print("Potansiyometre = ");
  Serial.println(potansiyometre);
  */
}
