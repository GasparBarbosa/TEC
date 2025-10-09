#include <Arduino.h>
const int LED= 8;
const int Botao= 2;
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(Botao, INPUT);
}

void loop()
{
while(digitalRead(Botao)==LOW)
{
  digitalWrite(LED, HIGH);
  delay(500);
}

  digitalWrite(LED, LOW);
  delay(500);
  
}



