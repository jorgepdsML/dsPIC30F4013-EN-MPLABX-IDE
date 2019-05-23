
#                                           dsPIC30F4013-EN-MPLABX-IDE
                         TIMER1 DEL DSPIC30F4013 Y APLICACION CON EL SENSOR DE ULTRASONIDO
El circuito consiste en estimar la distancia mediante el uso de un sensor de ultrasonido HC SR04 , la cual puede estimar una maxima distancia de 4 metros o de 400 cm , en el programa se hace uso de 1 decimal adicional para poder mostrarlo en una pantalla LCD de 16x2,la cual funciona mediante el uso de las librerias xlcd.h y xlcd.c, para poder estimar las distancias hacemos uso de un temporizador especificamente el TIMER1 DE DSPIC30F4013 en el software MPLABX IDE y el compilador XC16.

#


En el archivo xlcd.h se encuentra las definiciones de los pines de datos del dspic30f4013  y la pantalla Lcd 16x2,como tambien las declaraciones de funciones y comandos para el manejo de la pantalla LCd 

En el archivo reloj.h solo se define la frecuencia de ciclo de instruccion FCY = PLL*FOSC/4

En el archivo config.h se define los bits de configuracion  

En el archivo main.c se encuentra el archivo de codigo fuente principal donde esta todo el codigo para la aplicacion de la medicion de distancia usando el dspic30f4013 y el temporizador 1





Para mas detalles ir al siguiente link donde se realiza la explicacion del uso de timer 1 y el ultrasonido con el dsPIC30F4013.
part1:
https://www.youtube.com/watch?v=Fxhftv6uW3E&list=PLOYWpTa8jSmuM8tJ8CTfDjgs4jQ4T7MET&index=2 .

parte2:
https://www.youtube.com/watch?v=cX6tq58z3tc&list=PLOYWpTa8jSmuM8tJ8CTfDjgs4jQ4T7MET&index=3 .
 

 
