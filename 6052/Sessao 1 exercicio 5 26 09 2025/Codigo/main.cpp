#include <Arduino.h>
 int temperatura_lida = 5;
 int temperatura_maxima = 3;
 int temperatura_minima = 2;
 int estado_do_botao = 6;
 int LED = 7;
 int botao_arranque_1 = 0;
 int botao_arranque_2 = 0;
 int sobrecarga = 0;




 void setup()
 {
  Serial.begin(9600);
 }

 void loop()
 {
  if(digitalRead(estado_do_botao)== LOW)
  {
    digitalWrite(LED, HIGH);
    Serial.println("Botao pressioando");
    Serial.println("LED ligado");
    }
    else
    {
      digitalWrite(LED, LOW);
      Serial.println("Botao nao pressioando");
      Serial.println("LED desligado");
      }
      if( temperatura_lida > temperatura_maxima)
  {
    Serial.println("ligar ventoinha");
    }
      else
    {
 
  Serial.println("desligar ventoinha");
  }
  
  if (temperatura_lida < temperatura_minima)
  {
    Serial.println("ligar esquentador");
    }
    else
    {
      Serial.println("desligar esquentador");
      }

  if(botao_arranque_1 && botao_arranque_2)
  {
    Serial.println("ligar maquina");
  }
  else
  {
    Serial.println("desligar maquina");
    }
    if((temperatura_lida > temperatura_maxima) || sobrecarga)
    {
      Serial.println("Desligar maquina");
    }
    else
    {
      Serial.println("Continuar ligada");
      }

      delay(3000);
}
