 //ver el tutorial de jorge miranda redes neuronales 
//lista de reproduccion programacion dspic30f4013 en mplabx ide
//INCLUIR CABECERAS
#include "config.h"
#include "reloj.h"
#include <libpic30.h>
#include "xlcd.h"
#include <stdio.h>
//DECLARACION DE VARIABLES ,VECTORES Y FUNCIONES
void config_timer1(void);
int cont=0;
float dist;
char dists[6]="";
//FUNCION PRINCIPAL main
int main(void) 
{   
    //ESTABLECER PUERTOS DE ENTRADA Y SALIDA
    TRISFbits.TRISF0=1;//ECHO
    TRISFbits.TRISF1=0;//TRIGGER
    //DUNCIONES DEL LCD 
    XLCDInit();
    XLCDgotoXY(1,0);
    putsXLCD("DIST :");
    //LLAMAR A LA FUNCION config_timer 1()
    config_timer1();
    while(1)
    {//10us  de pulso
        LATFbits.LATF1=1;
        __delay_us(10);
        LATFbits.LATF1=0;
        while(!PORTFbits.RF0);
    //flanco de subida en el pin ECHO
        //INICIAR LA TEMPORIZACION
        T1CONbits.TON=1;
        //PREGUNTAR SI EL PIN ECHO VOLVIO A CERO VOLTIOS
        //O SI HAY NO HAY OBJETO DENTRO DEL RANGO DE LOS 4 METROS O 400 cm
        while(PORTFbits.RF0==1&&IFS0bits.T1IF==0);
         //DETENER LA CUENTA     
        T1CONbits.TON=0;   
        //SABER SI ESTA DENTRO DEL RANGO DE DISTANCIA DATO POR EL
        //DATASHEET DE SENSOR ULTRASONICO
        if(PORTFbits.RF0==0)
        {
            cont=TMR1;
            dist=(float)(cont*12.8)/58;//CENTIMETROS
            //Convertir de flotante con 1 decimal a caracteres
            sprintf(dists,"%.1f",dist);
            //CONDICIONAL PARA LAS DISTANCIAS 
            //PARA EVITAR EL SUPERPOSICION DE CARACTERES
            //EN LA PANTALLA LCD DEBIDO AL CAMBIO DE DISTANCIAS
            if(dist<10)
            { 
            XLCDgotoXY(1,10);
            putsXLCD("  ");
            XLCDgotoXY(1,7);
            putsXLCD(dists);
            }
                
                else 
                { 
                    if (dist<100)
                    {
             XLCDgotoXY(1,11);
            putsXLCD(" ");        
            XLCDgotoXY(1,7);
            putsXLCD(dists);
                    }
                    else
                    { 
            XLCDgotoXY(1,7);
            putsXLCD(dists);
                    
                    }
                }
             
             //REINICAR EL CONTADOR A CERO
            TMR1=0;
            // REFRESCAR PRESCALER
            T1CONbits.TCKPS=0b10;
            //BORRAR FLAG DEL TIMER 1
            IFS0bits.T1IF=0;
        }
        //ESTA CONDICION INDICA DE QUE SE SALIO DE BUCLE WHILE
        //DEBIDO A QUE SUPERO EL RANGO ESPECIFICADO POR PR1
        if(IFS0bits.T1IF==1)
        {
            IFS0bits.T1IF=0;
        TMR1=0;
        T1CONbits.TCKPS=0b10;
        }
        
        
    }
    return 0;
}
void config_timer1(void)
{//MODO  TEMPORIZADOR
    T1CONbits.TCS=0;
    //prescale 1:64
    T1CONbits.TCKPS=0b10;
    //TMR1=0
    TMR1=0x0000;
    //DETERMINAR EL PERIODO PR1
    PR1=1812;
}