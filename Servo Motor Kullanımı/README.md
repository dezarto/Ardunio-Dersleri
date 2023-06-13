# Servo Motor Nasıl Kullanılır ?

![Servo Motor](https://raw.githubusercontent.com/dezarto/Ardunio-Dersleri/main/Gerekli%20G%C3%B6rseller/arduino-servo-motor.jpg)
<br/> Servo motor arduino bağlantısını aşağıdaki şemayı inceleyerek yapabilirsiniz. <br/>
![Servo Motor Bağlantı Şeması](https://raw.githubusercontent.com/dezarto/Ardunio-Dersleri/main/Gerekli%20G%C3%B6rseller/arduino-ile-servo-motor-ba%C4%9Flant%C4%B1s%C4%B1-1.jpg)

## Servo motor arduino kodları nasıl yazılır?

1. Adım: Gerekli kütüphanenin eklenmesi <br/>
  `#include<Servo.h>` <br/>
2. Adım: `Servo motor_ismi;` kodu ile arduinoya bağladığınız servo motora bir isim vererek kodlama içinde kolaylıkla kullanabilirsiniz. <br/>
  `motor_ismi.attach(pwm pin numarası);` kodu ile yukarıdaki kod ile isim verdiğimiz servo motoru arduinoya bağladığımız pin numarasını belirtiyoruz. Örneğin; servo motora `servo1` adını verdiniz ve 5 numaralı pwm pinine bağladınız. Bu durumda kodlar şu şekilde olmalıdır.<br/>
  <br/>
  
  `#include<Servo.h>` <br/>
`Servo servo1;` <br/>

`void setup() {` <br/>
`servo1.attach(5);` <br/>
`}` <br/> 
<br/>
Tanımlamaları yaptıktan sonra `servo1.write(açı_değeri);` kodu ile servo motoru `0-180 derece` arasında istediğimiz bir açı değerine dönmesini sağlayabiliriz. <br/>
Kodları toparladığımızda aşağıdaki gibi olmalıdır. <br/>
<br/>
`#include<Servo.h>` <br/>
`Servo servo1;` <br/>
`int aciDegeri=90;` <br/>
 
`void setup() {` <br/>
` servo1.attach(5);` <br/>
`}` <br/>
 
`void loop() {` <br/>
`servo1.write(aciDegeri);` <br/>
`}` <br/>
<br/>
