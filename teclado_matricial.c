#define vermelho pin_d2
#define amarelo pin_d0
#define verde pin_d1
#include<18F4550.h>
#use delay (clock=20000000)        
#fuses HS,PLL5, CPUDIV1, USBDIV
#use rs232(baud=9600, xmit = PIN_C6, rcv = PIN_C7)
#include "12Keys.c"
#include <string.h>

boolean flag;
char *senha="70030";
int contador = 0;
int errado = 0;


void main()
 {
  port_b_pullups(True);
  
    
  tecla_pres=0;
   
  while(TRUE)
              {
               tecla = trata_teclas();
               
               if (tecla_pres){
                  printf("%c",tecla); 
                  
                  if(senha[contador] != tecla && contador<5){
                     errado = 1;
                  }
                  
                  
                     contador++;
                  
                  
               }
               
               if((errado || contador>6) && tecla == '#'){
                  output_high(vermelho);
                  delay_ms(5000);
                  output_low(vermelho);
                  contador = 0;
                  errado = 0;
               }
               
               if(contador == 6 && !errado && tecla == '#'){
                  output_high(verde);
                  delay_ms(5000);
                  output_low(verde);
                  contador = 0;
                  errado = 0;
               }
               
               
}
}
