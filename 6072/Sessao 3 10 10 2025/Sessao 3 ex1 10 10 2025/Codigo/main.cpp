#include <Arduino.h>

typedef struct Gyokeres_marca_golo
{
  unsigned long tempo_anterior;
  unsigned long intervalo;
  
};

Gyokeres_marca_golo GOLO1;


void setup() 
{
  Serial.begin(9600);
  GOLO1.tempo_anterior= millis();
  GOLO1.intervalo = 1000;
}

void loop() 
{
  //conta 1 segundo e executa a acao
  if (millis()- GOLO1.tempo_anterior > GOLO1.intervalo)
  {
    Serial.println("Gyokeres marca golo");
     GOLO1.tempo_anterior= millis();
  }
}
  


