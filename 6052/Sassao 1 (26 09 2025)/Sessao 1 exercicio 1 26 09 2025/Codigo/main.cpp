#include <Arduino.h>

void setup()
{
  Serial.begin(115200);
}
void loop()
{
  Serial.println("Olá");
  delay(2000);
  Serial.println(" E Xau");
  delay(2000);
}