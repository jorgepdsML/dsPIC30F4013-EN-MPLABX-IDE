
#                                           dsPIC30F4013-EN-MPLABX-IDE
TIMER1 DEL DSPIC30F4013 Y APLICACION CON EL SENSOR DE ULTRASONIDO
El circuito consiste en estimar la distancia mediante el uso de un sensor de ultrasonido HC SR04 , la cual puede estimar una maxima distancia de 4 metros o de 400 cm , en el programa se hace uso de 1 decimal adicional para poder mostrarlo en una pantalla LCD de 16x2,la cual funciona mediante el uso de las librerias xlcd.h y xlcd.c, para poder estimar las distancias hacemos uso de un temporizador especificamente el TIMER1 DE DSPIC30F4013 en el software MPLABX IDE y el compilador XC16, Para mas detalles ir al siguiente link donde se realiza la explicacion del uso de timer 1 y el ultrasonido con el dsPIC30F4013.

parte1:
https://www.youtube.com/watch?v=Fxhftv6uW3E&list=PLOYWpTa8jSmuM8tJ8CTfDjgs4jQ4T7MET&index=2 .

parte2:

https://www.youtube.com/watch?v=cX6tq58z3tc&list=PLOYWpTa8jSmuM8tJ8CTfDjgs4jQ4T7MET&index=3 .
CONEXIONES DEL DSPIC30F4013 Y LA PANTALLA LCD 16x2 

PUERTO D               PINES DE 
   DEL                  DATOS 
DSPIC30F4013        PANTALLA LCD 16x2
 RD0                        D4
 RD1                        D5
 RD2                        D6
 RD3                        D7

PUERTO B              PINES DE 
  DEL                 CONTROL
DSPIC30F4013       PANTALLA LCD 16x2
RB9                        E(ENABLE) 
RB10                       RS
RB11                       RW

PUERTO F             PINES 
  DEL                 DEL
DSPIC30F4013          HC SR04  

RF0                  Echo
RF1                  Trig
