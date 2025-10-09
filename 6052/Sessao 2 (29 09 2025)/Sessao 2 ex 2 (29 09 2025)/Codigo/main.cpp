#include <Arduino.h>

const int Botao = 3;

void setup() 
{
  // configurar monitor
  Serial.begin(9600);

  // configurar periferico
  pinMode(Botao, INPUT);
}

void loop() 
{
  //enquanto o Botao esta a ser pressioando
  while(digitalRead(Botao)== LOW)
  {
    //contar mais um
    Serial.println("+1");
    //esperar 500
    delay(500);
  }

}



