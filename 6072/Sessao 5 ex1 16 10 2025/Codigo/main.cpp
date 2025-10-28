#include <Arduino.h>


//Criar variável relé

typedef struct rele
{
  int estado;
  int periferico;
};

rele reles[3];

// criar estrutura do botão

typedef struct botao
{
  int estado;
  int periferico;
};

botao botoes[3];


void setup() 
{
  Serial.begin(9600); //dar início ao monitor serial
  
  //definir periferico do relé
  reles[0].periferico = 5; // periferico 5 para rele 1
  reles[1].periferico = 6; //periferico 6 para rele 2
  reles[2].periferico = 7;
  reles[3].periferico = 8;

  //estado do relé
  reles[0].estado = 0; //estado do rele 1 começa LOW
  reles[1].estado = 0; //estado do rele 2 começa LOW
  reles[2].estado = 0;
  reles[3].estado = 0;
  
  
  // definir periferico do botao
  botoes[0].periferico = A0;
  botoes[1].periferico = A1;
  botoes[2].periferico = A2;
  botoes[3].periferico = A3;
  
  //definir estado dos botões  
  botoes[0].estado = 0; //estado do rele 1 começa LOW
  botoes[1].estado = 0; //estado do rele 2 começa LOW
  botoes[2].estado = 0; //estado do rele 3 começa LOW
  botoes[3].estado = 0; //estado do rele 4 começa LOW
  
  pinMode(reles[0].periferico,OUTPUT); // define periferico de rele 1 como OUTPUT
  pinMode(reles[1].periferico,OUTPUT); // define periferico de rele 2 como OUTPUT
  pinMode (reles[2].periferico, OUTPUT); // define periferico de rele 3 como OUTPUT
  pinMode (reles[3].periferico, OUTPUT); // define periferico de rele 4 como OUTPUT
  
  
  pinMode(botoes[0].periferico,INPUT); // define periferico de rele 1 como OUTPUT
  pinMode(botoes[1].periferico,INPUT); // define periferico de rele 2 como OUTPUT
  pinMode (botoes[2].periferico, INPUT); // define periferico de rele 3 como OUTPUT
  pinMode (botoes[3].periferico, INPUT); // define periferico de rele 4 como OUTPUT
}

void loop (){
 

  botoes[0].estado = !digitalRead (botoes[0].periferico);
  botoes[1].estado = !digitalRead (botoes[1].periferico);
  botoes[2].estado = !digitalRead (botoes[2].periferico);
  botoes[3].estado = !digitalRead (botoes[3].periferico);
  
  Serial.println ("b0 - ");
  Serial.println(botoes[0].estado);

    if (digitalRead (botoes[0].periferico) == HIGH)
    if(botoes [0].estado)
    {
        
          digitalWrite (reles[0].periferico,LOW);
          digitalWrite (reles[0].periferico, reles[0].estado);
        }
        else
        {
          digitalWrite (reles[0].periferico, HIGH);
          digitalWrite (reles[0].periferico, reles[0].estado);
        }

        if (digitalRead (botoes[1].periferico) == HIGH)
        if(botoes [1].estado)
        {
        
          digitalWrite (reles[1].periferico,LOW);
          digitalWrite (reles[1].periferico, reles[1].estado);
        }
        else
        {
          digitalWrite (reles[1].periferico, HIGH);
          digitalWrite (reles[1].periferico, reles[1].estado);
        }

        if (digitalRead (botoes[2].periferico) == HIGH)
        if(botoes [2].estado)
        {
        
          digitalWrite (reles[2].periferico,LOW);
          digitalWrite (reles[2].periferico, reles[2].estado);
        }
        else
        {
          digitalWrite (reles[2].periferico, HIGH);
          digitalWrite (reles[2].periferico, reles[2].estado);
        }
     delay(500);
    }
  


