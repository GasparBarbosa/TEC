#include <Arduino.h>
 


//Configurar structs
typedef struct Temporizador
{
unsigned long intervalo;
unsigned long tempo_anterior;
};


typedef struct Rele
{
  int estado;
  int periferico;

  Temporizador temporizador [3];
 
};

Rele rele [3];




void setup() 
{
  //Configurar Portas
  Serial.begin(9600);
  
  rele [0].periferico = 7; //rele 1
  rele [1].periferico = 8; //rele 2
  rele [2].periferico = 9; //rele 3
 
  pinMode(rele [3].periferico, OUTPUT);
  
  rele [3].temporizador[3].tempo_anterior = millis();
  
  rele [0].temporizador[0].intervalo = 5000; //5 segundos
  rele [1].temporizador[1].intervalo = 10000; //10 segundos
  rele [2].temporizador[2].intervalo = 15000; //15 segundos
  
}

void loop() 
{
  //ligar rele1 a cada 5 segundos e rele2 a cada 10 segundos
  if(millis()-rele [0].temporizador [0].tempo_anterior > rele [0].temporizador[0].intervalo);
  if(millis()-rele [1].temporizador [1].tempo_anterior > rele [1].temporizador[1].intervalo);
  if(millis()-rele [2].temporizador [2].tempo_anterior > rele [2].temporizador[2].intervalo);

 
  {
    
    //executar açao
    Serial.println("Liga o rele");
    
    
    //ligar e desligar o relle1
    if(digitalRead(rele[0].periferico))
    {
      digitalWrite(rele [0].periferico, LOW);
      Serial.println("Desliga o rele1");
    }
    else
    {
      digitalWrite(rele [0].periferico, HIGH);
      Serial.println("Liga o rele1");
    }
    rele[0].temporizador [0].tempo_anterior = millis();

    
    //executar açao
    Serial.println("Liga o rele 2");
    
    
    //ligar e desligar o relle2
    if(digitalRead(rele [1].periferico))
    {
      digitalWrite(rele [1].periferico, LOW);
      Serial.println("Desliga o rele 2");
    }
    else
    {
      digitalWrite(rele [1].periferico, HIGH);
      Serial.println("Liga o rele 2");
    }
    rele [1].temporizador [1].tempo_anterior = millis();
    
    
    
    //executar açao
    Serial.println("Liga o rele 3");
    
    
    //ligar e desligar rele 3
    if(digitalRead(rele [2].periferico))
    {
      digitalWrite(rele [2].periferico, LOW);
      Serial.println("Desliga o rele 3");
    }
    else
    {
      digitalWrite(rele [2].periferico, HIGH);
      Serial.println("Liga o rele 3");
    }
    rele [2].temporizador [2].tempo_anterior = millis();
  }
    

}