/*
* LDR(Light Dependent Resistor)
* Bu projede LDR ile ortamda eğer ışık var ise ledimizin sönmesi karanlık
* bir ortamda ise ledimizin yanması programlanmıştır.
* Yazar: dezarto
* Tarih: 10.06.2023
*/
#define LED 3
#define LDR A0

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  Serial.println(analogRead(LDR));

  if(analogRead(LDR) < 150){
    digitalWrite(LED, 1);
  }
  else{
    digitalWrite(LED, 0);
  }

}
