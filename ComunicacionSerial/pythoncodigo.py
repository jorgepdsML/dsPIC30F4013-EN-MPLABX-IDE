from tkinter import *
from tkinter.font import Font
from time import sleep 
import serial
import time
import sys
#CREAR PUERTO SERIAL PARA LA COMUNICACION  USANDO PYTHON
puerto= serial.Serial()
#DEFINIR VELOCIDAD EN BAUDIOS
puerto.baudrate=9600
puerto.timeout=3#tiempo hasta recibir un caracterer de fin de linea
#DEFINIR PUERTO COM DEL FTDI232
puerto.port='COM4'
#ABRIR UNA CONEXION SERIAL
puerto.open()
print('PUERTO SERIAL LISTO PARA LA COMUNICAICON')
#Crear un objeto Tk() 
vent=Tk()
#TITULO DE LA INTERFAZ
vent.title("     COMUNICACION SERIAL PYTHON   -  DSPIC30F4013")
#DIMENSIONES DE LA INTERFAZ
vent.geometry('320x300')
#----------------------------------------
#CREACION DE FUNCIONES ASOCIADOS A CADA BOTON DE LA INTERFAZ GRAFICA
def button1(): #CUANDO SE PRESIONA EL BOTON DE "LED ON"
    global vent
    mystring=str(2)
    b = mystring.encode('utf-8')
    print("BOTON 1 SE HA PRESIONADO")
    puerto.write(b)#ESCRIBIR 
    tex.delete(1.0,END)
    #INSERTAR UN MENSJAE EN LA INTERFAZ GRAFICA
    tex.insert(1.0,"LED ENCENDIDO") 
def button2():#CUANDO SE PRESIONA EL BOTON DE "LED OFF"
    global vent
    mystring=str(1)
    b = mystring.encode('utf-8')
    puerto.write(b)
    print("BOTON 2 PRESIONADO")
    tex.delete(1.0,END)
    #INSERTAR UN MENSJAE EN LA INTERFAZ GRAFICA
    tex.insert(1.0,"LED APAGADO")

def button3():#CUANDO SE PRESIONA EL BOTON DE "LED BLINK"
    global vent
    mystring=str(3)
    b = mystring.encode('utf-8')
    print("BOTON 3 SE HA PRESIONADO")
    puerto.write(b)
    tex.delete(1.0,END)
    #INSERTAR UN MENSJAE EN LA INTERFAZ GRAFICA
    tex.insert(1.0,"LED PARPADEANDO")
#-------------------------------------------------------------------------------------
#CREACION DE BOTONES
l1=Button(vent,text='LED ON',command=button1,cursor='circle')
l2=Button(vent,text='LED OFF',command=button2,cursor='circle')
l3=Button(vent,text='LED BLINK',command=button3,cursor='arrow') 
#CREACION DE ETIQUETAS 
lab1=Label(vent,text='   ESTADO DEL LED',width=15,height=3)
lb2=Label(vent,text='PYTHON COMUNICACION SERIAL DSPIC30F4013',width=38,height=4)
#CREACION DE TEXTO
tex= Text(vent,width=20,height=2)
#ESTABLECER POSICIONES DE LOS BOTONES EN LA INTERFAZ GRAFICA
l1.place(x=130,y=200)
l2.place(x=220,y=200)
l3.place(x=160,y=250)
#ESTABLECER POSICIONES DE LAS ETQIUETAS Y TEXTOS EN LA INTERFAZ GRAFICA
lab1.place(x=150,y=100)
lb2.place(x=48,y=40)
tex.place(x=125,y=140)
vent.mainloop()
#CERRAR EL PUERTO SERIAL
puerto.close()
print('PUERTO BLOQUEADO')
sys.exit(0)
