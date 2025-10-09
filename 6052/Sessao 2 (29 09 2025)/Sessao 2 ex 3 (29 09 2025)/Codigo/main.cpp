#include <Arduino.h>
const int Botao_da_direita = 10;
const int Botao_da_esquerda = 12;
const int LED_D = 2;
const int LED_E = 4;
void setup() 
{
  Serial.begin(9600);
  pinMode(Botao_da_esquerda, INPUT);
  pinMode(Botao_da_direita, INPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_E, OUTPUT);
}
 
 void loop() 
{
  //enquanto o Botao esta a ser pressioando
  while(digitalRead(Botao_da_esquerda)== LOW)
  {
    //obejto desloca-se para a direita
    Serial.println("vai objeto para a esquerda");
    //LED Direita ligado
    digitalWrite( LED_D, HIGH);
    //espera 500
    delay(500);
  }
  digitalWrite(LED_D, LOW);
  //enquanto o Botao esta a ser pressionado
  while(digitalRead(Botao_da_direita)== LOW)
  {
    //objeto desloca-se para a direita
    Serial.println("vai objeto para a direita");
    //LED Esquerda
    digitalWrite( LED_E, HIGH);
    //espera 500
    delay(500);
  }
    digitalWrite(LED_E, LOW);
}    