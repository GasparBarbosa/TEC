#include <Arduino.h>

const int LED = 5;
int opcao = 4;

void setup() 
{
Serial.begin(9600);  
pinMode(LED, OUTPUT);
}
void loop() 
{
  switch (opcao)
{
  case 0:
  Serial.println("Temperatura normal");
  break;

  case 1:
  Serial.println("Temperatura baixa");
  break;

  case 2:
  Serial.println("Temperatura alta");
  break;

  case 3:
  Serial.println("Temperatura superior a 25");
  break;

  default:
  Serial.println("Opçao nao existe");
  break;
  }

}
  
