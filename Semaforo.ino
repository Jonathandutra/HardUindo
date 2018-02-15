/*                         ================ | Harduino  | ==========
 *Nome: Semaforo interativo
 *Descrição: Codigo fonte com o intuido de auxiliar  
 *no entendimento do iniciante em arduino, esse codigo irá simular um semafaro interativo 
 *ele permancessera acesso para os carros (ou seja verde para os carros)  e vermelho para os pedestres 
 *quando o pedestre pressionar um botao o semaforo devera permitir a passagem do pedestre e apagar para o carro    
 *    
 *Autor: Projeto Harduino 
 *Versão: 0.0001
 *Data: 09/02/2018
 *contatos: harduino.slack.com
 */ 



// semaforo para carros
 int carRed = 12;
 int carYellow =11; 
 int carGreen =10;
 
 //semaforo para pedestre 
 int pedRed = 9;
 int pedGreen = 8;

// controle 
int btn = 2; // botão 
int travessia = 5000;
unsigned long tempoPassado;

void setup (){
    //Modo de operção dos pino selecionados 
    pinMode(carRed,OUTPUT);
    pinMode(carYellow,OUTPUT);
    pinMode(carGreen,OUTPUT);
    pinMode(pedRed,OUTPUT);
    pinMode(pedGreen,OUTPUT);
    pinMode(btn,INPUT);

    digitalWrite(carGreen,HIGH);
    digitalWrite(pedRed,HIGH); 

     }
  void loop(){
      int btn_Valor = digitalRead(btn); // guarda o valor do botão 
      if(btn_Valor == HIGH)
      {
          fall();/* Chama a fuão fall ( O nome foi sugerido em aula, observe que poderia ser qualquer nome ) */
          btn_Valor = LOW;
      }
    }
/* A função fall() , server para fazer o controle do semaforo */

  void fall(){
      digitalWrite(carGreen,LOW);
      digitalWrite(carYellow,HIGH);
      delay(2000);
      digitalWrite(carYellow,LOW);
      digitalWrite(carRed,HIGH);

      digitalWrite(pedRed,LOW);
      digitalWrite(pedGreen,HIGH);
      delay(travessia);
      digitalWrite(pedGreen,LOW);
// nesta parte fazemos o luz vermelha do pedestre piscar 5 vezes 

      for(int x = 0;x<5;x++){
        digitalWrite(pedRed,HIGH);
        delay(1000);
        digitalWrite(pedRed,LOW);
        delay(1000);
        } 
      
      digitalWrite(pedRed,HIGH);
      digitalWrite(carRed,LOW);
      digitalWrite(carGreen,HIGH);
    

 }





 
