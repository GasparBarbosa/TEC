#include <Arduino.h>


int periferico =10;
int periferico2 =11;

//int tempo_atual= 0;
//unsigned tempo_atual =0;
unsigned long tempo_atual = 0;
unsigned long tempo_anterior = 0;
unsigned long tempo_atual_2 = 0;
unsigned long tempo_anterior_2 = 0;

void setup() 
{
  
  Serial.begin(9600);
  pinMode(periferico, OUTPUT);
  pinMode(periferico2, OUTPUT);
}
void loop()
{
   //Temporizador 2
  tempo_atual=millis();
   
   if (tempo_atual- tempo_anterior > 1000)
   {
     Serial.print("tempo_atual - ");
     Serial.println(tempo_atual);
     
     Serial.print("tempo_anterior - ");
     Serial.println(tempo_anterior);


     //piscar o LED1
     if (digitalRead(periferico)==LOW)
    
     {
      digitalWrite(periferico, HIGH);
     }
     else
     {
      digitalWrite(periferico, LOW);
     }
     
     tempo_anterior = millis();
     }
    ///////////////////////////////////////////
    
    
    //temporizador 2
     tempo_atual_2 = millis();
     
     if(tempo_atual_2 - tempo_anterior_2 > 2000)
     
     {
     //piscar o LED2
     if (digitalRead(periferico2)==LOW)
    
     {
      digitalWrite(periferico2, HIGH);
     }
     else
     {
      digitalWrite(periferico2, LOW);
     }
     
     tempo_anterior_2 = millis();
  
     //delay(1000);
     //Serial.println("passou 1 segundo");
   }
}

 