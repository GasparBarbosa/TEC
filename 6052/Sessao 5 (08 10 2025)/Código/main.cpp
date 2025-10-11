#include <Arduino.h>

int opcao = 0;


typedef struct Botao
{
  int periferico;
  int estado;
};

Botao botao1;
Botao botao2;
Botao botao3;
Botao botao4;


void setup() 
{
  //configurar valores
  botao1.periferico = 4;
  botao2.periferico = 5;
  botao3.periferico = 6;
  botao4.periferico = 7;
  
  
  //configurar portas
  Serial.begin(9600);
  pinMode(botao1.periferico, INPUT);
  pinMode(botao2.periferico, INPUT);
  pinMode(botao3.periferico, INPUT);
  pinMode(botao4.periferico, INPUT);
  

}

void loop() 
{
  //igualar estado a periferico
  botao1.estado = !digitalRead(botao1.periferico);
  
  
  botao2.estado = !digitalRead(botao2.periferico);
  
 
  botao3.estado = !digitalRead(botao3.periferico);
  
  
  botao4.estado = !digitalRead(botao4.periferico);
 
  
  
  //nenhum botao pressioando
  if (!botao1.estado && !botao2.estado && !botao3.estado && !botao4.estado)
  {
    opcao = 0;
  }
  
  //botao1 seta esquerda
  if (botao1.estado && !botao2.estado && !botao3.estado && !botao4.estado)
  {
    opcao = 1;
  }
  
  //botao2 seta cima
  if (!botao1.estado && botao2.estado && !botao3.estado && !botao4.estado)
  {
    opcao = 2;
  }
  
  //botao3 seta baixo
  if (!botao1.estado && !botao2.estado && botao3.estado && !botao4.estado)
  {
    opcao = 3;
  }
  
  //botao4 seta direita
  if (!botao1.estado && !botao2.estado && !botao3.estado && botao4.estado)
  {
    opcao = 4;
  }
  
  //botao 1 e botao 2, seta diagonal esquerda cima
  if(botao1.estado && botao2.estado && !botao3.estado && !botao4.estado)
  {
    opcao = 5;
  }
  
   switch (opcao)
   {
    case 0:
    Serial.println("nenhuma seta acioanda");
    digitalWrite(botao1.periferico, LOW);
    digitalWrite(botao2.periferico, LOW);
    digitalWrite(botao3.periferico, LOW);
    digitalWrite(botao4.periferico, LOW);
    break;
    
    case 1:
    Serial.println("aciona seta esquerda");
    digitalWrite(botao1.periferico, HIGH);
    digitalWrite(botao2.periferico, LOW);
    digitalWrite(botao3.periferico, LOW);
    digitalWrite(botao4.periferico, LOW);
    break;

    case 2:
    Serial.println("aciona seta cima");
    digitalWrite(botao1.periferico, LOW);
    digitalWrite(botao2.periferico, HIGH);
    digitalWrite(botao3.periferico, LOW);
    digitalWrite(botao4.periferico, LOW);
    break;

    case 3:
    Serial.println("aciona seta baixo");
    digitalWrite(botao1.periferico, LOW);
    digitalWrite(botao2.periferico, LOW);
    digitalWrite(botao3.periferico, HIGH);
    digitalWrite(botao4.periferico, LOW);
    break;
   
    case 4:
    Serial.println("aciona seta direita");
    digitalWrite(botao1.periferico, LOW);
    digitalWrite(botao2.periferico, LOW);
    digitalWrite(botao3.periferico, LOW);
    digitalWrite(botao4.periferico, HIGH);
    break;

    case 5:
    Serial.println("aciona seta diagonal esquerda cima");
    digitalWrite(botao1.periferico, HIGH);
    digitalWrite(botao2.periferico, HIGH);
    digitalWrite(botao3.periferico, LOW);
    digitalWrite(botao4.periferico, LOW);
    break;
    
    default:
    Serial.println("erro");
    break;
   }

   delay(500);

  
}

