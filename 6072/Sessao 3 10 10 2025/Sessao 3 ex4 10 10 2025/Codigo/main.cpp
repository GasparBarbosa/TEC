#include <Arduino.h>

//Configurar structs
typedef struct Temporizador
{
unsigned long intervalo;
unsigned long tempo_anterior;
};
typedef struct rele
{
  int estado;
  int periferico;

  Temporizador temporizador1;
  Temporizador temporizador2;
};
rele rele1;
rele rele2;



void setup() 
{
  //Configurar Portas
  Serial.begin(9600);
  rele1.periferico = 7;
  rele2.periferico = 8;
  pinMode(rele2.periferico, OUTPUT);
  pinMode(rele1.periferico, OUTPUT);
  rele1.temporizador1.tempo_anterior = millis();
  rele2.temporizador2.tempo_anterior = millis();
  rele1.temporizador1.intervalo = 5000; //5 segundos
  rele2.temporizador2.intervalo = 10000; //10 segundos
  
}

void loop() 
{
  //ligar rele1 a cada 5 segundos e rele2 a cada 10 segundos
  if(millis()-rele1.temporizador1.tempo_anterior > rele1.temporizador1.intervalo);
  if(millis()-rele2.temporizador2.tempo_anterior > rele2.temporizador2.intervalo);
  {
    //executar açao
    Serial.println("Liga o rele");
    //ligar e desligar o relle1
    if(digitalRead(rele1.periferico))
    {
      digitalWrite(rele1.periferico, LOW);
      Serial.println("Desliga o rele1");
    }
    else
    {
      digitalWrite(rele1.periferico, HIGH);
      Serial.println("Liga o rele1");
    }
    rele1.temporizador1.tempo_anterior = millis();

    //ligar e desligar o relle2
    if(digitalRead(rele2.periferico))
    {
      digitalWrite(rele2.periferico, LOW);
      Serial.println("Desliga o rele2");
    }
    else
    {
      digitalWrite(rele2.periferico, HIGH);
      Serial.println("Liga o rele2");
    }
    rele2.temporizador2.tempo_anterior = millis();
  }
    

}
