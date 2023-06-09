/*
*
*   Örnek 2 - Buton ile sayaç kontrolü
*   Kullanılacak Komponentler:
*     Breadboard üzerine 2 tane buton bağlayın
*   Uygulama:
*     Butonlar bir tanesine basınc artan bir sayaç kurun ve sayacın değerini ekranda gösterin.
*     Diğer butona basınca sayaç azalsın ve değer ekranda gösterilsin.
*
*/

#define SAYAC_ILERI 4
#define SAYAC_GERI 8

int sayac_ileri, sayac_geri, sayi = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SAYAC_ILERI, INPUT);
  pinMode(SAYAC_GERI, INPUT);
}

void loop() {
  sayac_ileri = digitalRead(SAYAC_ILERI);
  sayac_geri = digitalRead(SAYAC_GERI);

  if(sayac_ileri){
    while(sayac_ileri){
      Serial.print("Test: "); Serial.println(sayi);
      sayi++;
      sayac_ileri = digitalRead(SAYAC_ILERI);
    }
  }

  if(sayac_geri){
    while(sayac_geri){
      Serial.print("Test: "); Serial.println(sayi);
      sayi--;
      sayac_geri = digitalRead(SAYAC_GERI);
    }
  }

}
