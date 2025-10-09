#include <Arduino.h>
const int LED = 2; 
const int Botao= 5;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(Botao, INPUT);

}

void loop() 
{
  if(digitalRead(LED)== LOW)
  {
  digitalWrite(LED, HIGH);
  Serial.println("Botao pressioando");
  }
  else
  {
  digitalWrite(LED, LOW);
  Serial.println("Botao nao pressioando");
  }

  delay(1000);
}
    