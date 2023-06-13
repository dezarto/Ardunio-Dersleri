# Joystick Nasıl Kullanılır ?

![Joystick X-Y](https://raw.githubusercontent.com/dezarto/Ardunio-Dersleri/main/Gerekli%20G%C3%B6rseller/arduino-joystick-x-y-eksen-hareketi.jpg)
arduino-joystick-x-y-eksen-hareketi <br/>
## Arduino ile Joystick Bağlantısı Nasıl Yapılır?

![Joystick Girişler](https://raw.githubusercontent.com/dezarto/Ardunio-Dersleri/main/Gerekli%20G%C3%B6rseller/joystick-arduino-baglantisi-nasil-yapilir.jpg)

Joystick modülünde 5 adet çıkış pini bulunmaktadır. Bunlar sırasıyla; Gnd, 5V, VRx, VRy ve SW pinleridir. Bu pinlerin arduino bağlantısı aşağıdaki resimdeki gibi yapılmalıdır. <br/><br/>
Hazırlayacağımız arduino devresinde VRx pinini A0, VRy pinin A1 analog pinlerine, SW pinini ise arduino 2 numaralı dijital pine bağlayacağız. Aşağıdaki arduino joystick bağlantı devresini hazırlayalım. <br/>
<br/> Joystick arduino bağlantısını aşağıdaki şemayı inceleyerek yapabilirsiniz. <br/>
![Joystick Bağlantı Şeması](https://raw.githubusercontent.com/dezarto/Ardunio-Dersleri/main/Gerekli%20G%C3%B6rseller/arduino-joystick-ba%C4%9Flant%C4%B1-devresi.jpg)

#### Örnek kod ve açıklamaları `test` dosyasında mevcuttur.
