/*
* 
* Örnek 3 - Buton ile Led Kontrolü
* Kullanilacak Komponentler:
*   Breadboard üzerine 2 tane buton baglayin 4 adet led badlayin
* Uygulama:
*   Butonlarin bir tanesine basili iken ledlerin tamamı yansin, aksi halde sönsün.
*   Diger butona basip çekince ledlerin tamama yansan, tekrar basip cekince sönsün
*/

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define BUTTON1 8
#define BUTTON2 9

int button_input;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  Serial.begin(9600);
}

void loop() {
  /*
  if (digitalRead(BUTTON1)) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  */
  
  if (digitalRead(BUTTON2)) {
    button_input = !(button_input);
    while(digitalRead(BUTTON2)){
      delay(100);
    }
    digitalWrite(LED1, button_input);
    digitalWrite(LED2, button_input);
    digitalWrite(LED3, button_input);
    digitalWrite(LED4, button_input);
  }
}
