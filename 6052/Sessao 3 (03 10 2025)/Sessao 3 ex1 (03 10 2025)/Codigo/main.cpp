#include <Arduino.h>


int estado_botao1 =0;
int estado_botao2 =0;

int botao1 =10;
int botao2 =12;

int opcao =0;

int led1 = 4;
int led2 = 6;

int estado_led1 = 0;
int estado_led2 =0;

 void leds(int estado_led1, int estado_led2)
 {
   digitalWrite(led1, estado_led1);
   digitalWrite(led2, estado_led2);
  }
 





//arranca codigo
void setup()

{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);

}
//repete codigo
void loop()

{
  
  //leitura dos botoes
  estado_botao2 = digitalRead(botao2);
  estado_botao1 = digitalRead(botao1);
  
  
  
  //quando os botoes nao estiverem pressioandos, nenhum led liga
  if(!estado_botao1 && !estado_botao2)
  {
    opcao=0;
  }
  
  
  
  //quando botao da esquerda pressionado, ligar led1
  if(estado_botao1 && !estado_botao2)
  {
    opcao=1;
  }

  
  
  //quando o botao da direta pressionado, ligar led2
  if(!estado_botao1 && estado_botao2)
  {
    opcao=2;
  }
  
  
  
  //quando ambos botoes pressioandos, ambos leds ligam
  if(estado_botao1 && estado_botao2)
  {
   opcao=3;
  }
  
  
  //trocar opcoes
  switch(opcao)
  {
    case 0:
     Serial.println("leds desligados");
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);

    case 1:
    Serial.println("led da esquerda liga");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);

    case 2:
    Serial.println("led da direita liga");
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    case 3:
    Serial.println("leds ligados");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
  }

delay(500);

}