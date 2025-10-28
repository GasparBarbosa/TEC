#include <Arduino.h>
#define numero_de_reles 3 //definir número de relés
#define numero_de_botoes 3 //definir número de botões


int contar=0; //inicializar variável contar

//Criar variável relé
typedef struct Rele
{
  int estado;
  int periferico;
};

Rele reles[numero_de_reles];


// criar estrutura do botão
typedef struct Botao
{
  int estado;
  int periferico;
};

Botao botoes[numero_de_botoes];



void setup() 
{
  Serial.begin(9600); //dar início ao monitor serial
  
  
  //definir periferico dos reles
  reles[0].periferico = 5; // periferico 5 para rele 1
  reles[1].periferico = 6; //periferico 6 para rele 2
  reles[2].periferico = 7; // periferico 7 para rele 3
  

  
  //definir periferico dos botoes
  botoes[0].periferico = 7;
  botoes[1].periferico = 8;
  botoes[2].periferico = 9;
  
  
  
  contar = 0; //inicializa a variável contar com 0
  
  while(contar < 3) //enquanto contar for menor que 3, faça
  {
    reles[contar].estado = 0; //estado do rele começa LOW
    botoes[contar].estado = 0; //estado do botao começa LOW

    pinMode(reles[contar].periferico,OUTPUT); // define periferico de rele como OUTPUT
    pinMode(botoes[contar].periferico,INPUT); // define periferico de botao como INPUT

    contar++; //contar = contar + 1;
  }
  
}

void loop ()
{
 
  contar = 0;  
  while (contar < 3)
  {
    botoes[contar].estado = !digitalRead (botoes[contar].periferico); //leitura dos estados de botoes invertidos
    if(botoes [contar].estado)
    
  {
    reles[contar].estado = HIGH;
    digitalWrite (reles[contar].periferico, reles[contar].estado);
    }
    else
    {
      reles[contar].estado = LOW;
      digitalWrite (reles[contar].periferico, reles[contar].estado);
    }
    contar++;
  }
    delay (500);
  
}
  
  