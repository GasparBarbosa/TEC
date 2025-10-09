#include <Arduino.h>s

const int BAUD_RATE = 9600;

void setup()
{
  Serial.begin(BAUD_RATE);

}
int test= -5;

void loop()

{ 
  if(test)
  {
    Serial.println("if");
  }
    else
  {
    Serial.println("else");
  }

  delay(2000);
}
    

  