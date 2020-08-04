#include "dht.h" //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal.h>
const int pinoDHT22 = A2; //PINO ANALÓGICO UTILIZADO PELO DHT11

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT; //VARIÁVEL DO TIPO DHT

// make some custom characters:
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  Serial.begin(9600);
  delay(1000); //INTERVALO DE 1 SEGUNDO
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);
  // create a new character
  lcd.createChar(0, heart);
  // create a new character
  lcd.createChar(1, smiley);
  // create a new character
  lcd.createChar(2, frownie);
  // create a new character
  lcd.createChar(3, armsDown);
  // create a new character
  lcd.createChar(4, armsUp);
}

void loop() {
  lcd.setCursor(0, 0);
  DHT.read22(pinoDHT22); //LÊ AS INFORMAÇÕES DO SENSOR
  Serial.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.humidity); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
  Serial.print("%"); //ESCREVE O TEXTO EM SEGUIDA
  Serial.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.temperature, 0); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
  Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
  lcd.print(DHT.humidity); //IMPRIME NA SERIAL O VALOR DE TEMPERATURA MEDIDO
  lcd.print("%"); //IMPRIME O TEXTO NA SERIAL
  lcd.setCursor(0, 1);
  lcd.print("Temperatura:"); //IMPRIME O TEXTO NA SERIAL
  lcd.print(DHT.temperature, 0); //IMPRIME NA SERIAL O VALOR DE TEMPERATURA MEDIDO
  lcd.print("*C"); //IMPRIME O TEXTO NA SERIAL
  delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR
}
