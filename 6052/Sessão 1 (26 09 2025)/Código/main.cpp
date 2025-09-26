#include <Arduino.h>

const int BAUD_RATE = 9600;
const int pinBotao= 2;
const int pinLED= 7;

//arrancar código
void setup()
{
 //definir pino de saída
  pinMode(pinBotao, INPUT);
  //definir pino de entrada
  pinMode(pinLED, OUTPUT);
  
  Serial.begin(BAUD_RATE);
}

void loop()
{
  //Quando carregar no Botão
  //Ler Botão
  Serial.println(digitalRead(pinBotao));
  if (digitalRead(pinBotao) == HIGH)
  {
    //Ligar LED
    digitalWrite(pinLED, HIGH);
    Serial.println("LED LIGA");
  }
  else
  {
    //Desligar LED
    digitalWrite(pinLED, LOW);
    Serial.println("LED DESLIGA");
    //esperar 1s
    delay(1000);
  }
}
