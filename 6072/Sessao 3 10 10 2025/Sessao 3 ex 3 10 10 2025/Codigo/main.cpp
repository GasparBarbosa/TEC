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
};

rele rele1;




void setup() 
{
  //Configurar Portas
  Serial.begin(9600);
  rele1.periferico = 7;
  pinMode(rele1.periferico, OUTPUT);
  rele1.temporizador1.tempo_anterior = millis();
  rele1.temporizador1.intervalo = 5000; //5 segundos
  
}

void loop() 
{
  //5 em 5 segundos liga o rele1
  if(millis()-rele1.temporizador1.tempo_anterior > rele1.temporizador1.intervalo);
  {
    //executar açao
    Serial.println("Liga o rele");
    //ligar e desligar o relle
    if(digitalRead(rele1.periferico))
    {
      digitalWrite(rele1.periferico, LOW);
      Serial.println("Desliga o rele");
    }
    else
    {
      digitalWrite(rele1.periferico, HIGH);
      Serial.println("Liga o rele");
    }
    rele1.temporizador1.tempo_anterior = millis();
  }

}



 