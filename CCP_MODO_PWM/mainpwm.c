#include <xc.h>
#include "reloj.h"
#include <libpic30.h>
 //variable global
int cont=0;
//declaracion de funciones
void pwm_init(void);
void input_init(void);
//funcion principal
 void main(void) 
{
     input_init();
     //leer
     while(1)
    { if(PORTDbits.RD3==0)
     { __delay_ms(200);
     while(!PORTDbits.RD3);
     LATCbits.LATC13=1;
     __delay_ms(1000);
     LATCbits.LATC13=0;
     __delay_ms(200);
      break;
     }
    
     }
     pwm_init();
    LATFbits.LATF0=1;
    LATFbits.LATF1=0;
     while(1)
     {
         if(PORTDbits.RD2==0)
     { __delay_ms(200);
     while(!PORTDbits.RD2);
     cont=cont+250;//10%
     if(cont>=2500)
     { cont=2500;
     }
     OC1RS=cont;//DUTYCYCLE
            }
           if(PORTDbits.RD8==0)
     { __delay_ms(200);
     while(!PORTDbits.RD8);
     cont=cont-250;//-10%
     if(cont<=0)
     {
         cont=0;
     }
     OC1RS=cont;
            }
       

     }
     
    return;
}
void pwm_init(void)
{
TRISDbits.TRISD0=0;//oc1
PR2=2499;//TPWM=1000useg
TMR2=0;//CONTADOR A 0
OC1R=0;//DUTY CYCLE INICIO 0 
OC1RS=0; 
 OC1CONbits.OCM=0b110; //MODO PWM
OC1CONbits.OCTSEL=0;//ELEGIR TIMER 2
T2CONbits.T32=0;//MODO 16 bits mode
T2CONbits.TCKPS=0b00;//PRESCALER 1:1
T2CONbits.TCS=0; //ELEGIR FUENTE TCY
T2CONbits.TON=1; //COMENZAR A CONTAR
}
void input_init(void)
{
    //PULSADORES PARA CONFIGURAR LA VELOCIDAD
    TRISDbits.TRISD2=1;
    TRISDbits.TRISD8=1;
    //PULSADOR PARA INICIAR EL PROGRAMA
    TRISDbits.TRISD3=1;
    //LED INDICADOR INICIO DE PROGRAMA
    TRISCbits.TRISC13=0;
    //PINES PARA EL SENTIDO DE GIRO
    TRISFbits.TRISF1=0;//IN1
    TRISFbits.TRISF0=0;//IN2
}