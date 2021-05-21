#include <LiquidCrystal.h>
 
// Biblioteca para o display
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void keyboardRead();
const int RELAYCOLD = 53; //Pino saida Relay Peltier
//const int RELAYHOT = 51; //Pino saida Relay Lampada
int adc_value = 0x00;
boolean up     = 0x00, butt02 = 0x00,
        down   = 0x00, butt03 = 0x00;

 
int SetPoint=26; //Define temperatura inicial desejado
//=================================================================
//                  SETUP
//=================================================================
void setup(){ 
  pinMode(RELAYCOLD,OUTPUT);  
//  pinMode(RELAYHOT,OUTPUT);
  lcd.begin(16, 2);
  // Print a mensagem para o LCD.  
  lcd.setCursor(0,1); //Move o cursor para a segunda linha 
  lcd.print("Controle de Temp.");
  digitalWrite(RELAYCOLD,LOW);       //Turn off Relay Peltier
//  digitalWrite(RELAYHOT,LOW);		//Turn off Relay Lampada
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("                ");
}
//=================================================================
//                  LOOP
//=================================================================  
void loop(){
  keyboardRead();

  //Botões para subir ou descer a temperatura (condição) 
  if(down == 0x01)
  {
    down = 0x00;
    
      SetPoint--;    

  }
  if(up == 0x01)
  {
    up = 0x00;
   
      SetPoint++;
    
  }
  
  double Temperature = ((5.0/1023) * analogRead(A8)) * 100;  //Calculo para 10mV por grau 0.01V/C 
 
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");    //
  lcd.print(Temperature);
  
//Display Set point on LCD
  lcd.setCursor(0,1);
  lcd.print("Temp Desej:");
  lcd.print(SetPoint);
  lcd.print("C   ");
 
//Verifica se a temperatura está no limite para acionar relay 
if(Temperature > SetPoint)
{
   digitalWrite(RELAYCOLD,LOW);    //Desliga Relay
}
else if (Temperature < SetPoint)
{
  digitalWrite(RELAYCOLD,HIGH);    //Liga Relay
 
}
/*if(Temperature < SetPoint)	//neste trecho de codigo se ativaria o relay
								//do atuador de aumento de temperatura, mas como
								//não foi apresentado no ponto de controle todas
								//as implementações relacionadas estão comentadas
{
   digitalWrite(RELAYHOT,LOW);    //Desliga Relay
}
else if (Temperature > SetPoint)
{
  digitalWrite(RELAYHOT,HIGH);    //Liga Relay
 
}*/
  delay(800); // Atualiza a cada 80ms
}


 

//O keypad shield utiliza uma entrada analogica para controlar os botoes
//devido a isso, e retornado um certo valor de tensao para cada botao pressionado
//assim e mapeado a tensao do botao "up" e o botao "down" para utilizacao.
void keyboardRead()
{
     adc_value = analogRead(A0);                       //Variavel para leitura recebe valor AD de A0

     // --- Testa se os botões foram pressionados ---
     // Se foi pressionado, seta a respectiva flag
     if (adc_value > 90 && adc_value < 200) butt02 = 0x01;
     else if (adc_value > 210 && adc_value < 380) butt03 = 0x01;
  
     
    

     // --- Testa se os botões foram liberados ---
     //

     if (adc_value > 200 && butt02)            //Botão up solto e flag butt02 setada?
     {                                         //Sim...
         butt02 = 0x00;                        //Limpa flag butt02
         up     = 0x01;                        //Seta flag up
      
     } //end up
     if (adc_value > 380 && butt03)            //Botão down solto e flag butt03 setada?
     {                                         //Sim...
         butt03 = 0x00;                        //Limpa flag butt03
         down   = 0x01;                        //Seta flag down
       
     }
}

       
     
