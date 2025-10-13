#include <Arduino.h>
int led = 2;
int botao = 4;
unsigned long int tempo_atual = 0;
unsigned long int tempo_anterior = 0;

int comeca_a_contagem = 0;

void setup()
{
Serial.begin(9600);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);  
  pinMode(botao, INPUT); 
 
}


void loop() 
{
   // se botao pressionado, comeca a contagem
    if (digitalRead(botao)==LOW)
    {
      comeca_a_contagem = 1;
      Serial.println("botao pressionado");      
    }

    if (comeca_a_contagem)
    {
      
      tempo_atual = millis();
      if (tempo_atual - tempo_anterior > 5000)
      {
        digitalWrite(led, HIGH);

        tempo_anterior = millis();
      }
    }
}

      
 

