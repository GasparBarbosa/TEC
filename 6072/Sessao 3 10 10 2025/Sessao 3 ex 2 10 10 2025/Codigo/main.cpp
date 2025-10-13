#include <Arduino.h>

typedef struct Gyokeres_marca_golo
{
  unsigned long tempo_anterior;
  unsigned long intervalo;
   
};

Gyokeres_marca_golo penalti;
Gyokeres_marca_golo livre;
Gyokeres_marca_golo bicicleta;

void setup() 
{
  Serial.begin(9600);
  penalti.tempo_anterior= millis();
  livre.tempo_anterior= millis();
  bicicleta.tempo_anterior= millis();

  penalti.intervalo= 1000; //1 segundo
  livre.intervalo= 2000; //2 segundos
  bicicleta.intervalo= 3000; //3 segundos

}

void loop() 
{
  //conta 1 segundo e executa a acao
  if (millis()- penalti.tempo_anterior > penalti.intervalo)
  {
    Serial.println("Gyokeres marca de penalti");
     penalti.tempo_anterior= millis();
  }
  
   //conta 2 segundos e executa a acao
  if (millis()- livre.tempo_anterior > livre.intervalo)
  {
    Serial.println("Gyokeres marca de livre");
     livre.tempo_anterior= millis();

  //conta 3 segundos e executa a acao
     if (millis()- bicicleta.tempo_anterior> bicicleta.intervalo)
  {
    Serial.println("Gyokeres marca de bicicleta");
     bicicleta.tempo_anterior= millis();
  }
  
  }
}
