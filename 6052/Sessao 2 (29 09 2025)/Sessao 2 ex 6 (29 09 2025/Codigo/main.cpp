#include <Arduino.h>
 const int BAUD_RATE=9600;
int botao1= 10;
int botao2=12;
int opcao= 4;
int led1= 3;
int led2=4;

void nenhum LED liga ()
{
  Serial.println("nenhum liga");
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
}
void ligar LED esquerda()
{
  Serial.println("led da esquerda liga");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);

}
void ligar LED direita()
{
  Serial.println("led da direita liga");
  digitalWrite(led2,HIGH);
  digitalWrite(led1,LOW);
}

void ligar ambos os LEDs ()
{
  Serial.println("os dois leds ligam");
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
}


void Erro ();
{
  Serial.println("esta opção não existe");
}



void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(botao1, INPUT);
  pinMode (botao2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop()
{
  //Ambos botoes nao pressioandos
  if (digitalRead(botao2)==LOW && digitalRead(botao1)==LOW)
  
  {
    opcao=2;
  }
  
  
  //Botao esquerdo pressionado
  if (digitalRead(botao1)==LOW)
  {
    opcao= 1;
  }
  
  
  //Botao Direito pressioando
  if (digitalRead(botao2)==LOW)
  
  {
    opcao=3;
  }
  
  
  //Ambos botoes pressioandos
  if (digitalRead(botao2)==HIGH && digitalRead(botao1)==HIGH)
  
  {
    opcao=4;
  }

  switch(opcao)
  {
  case 0:
  void nenhum LED liga ();
  break;
  
  case 1: 
  void ligar LED esquerda();
  break;

  
  case 2:
  void ligar LED direita();
  break;

  case 3:
  void ligar ambos os LEDs ()
  break;
  
  case default:
  void Erro ();
  break;

  default:
  Serial.println("esta opção não existe");
  break;

}
delay(500);

}