import kivy
kivy.require('2.0.0') # replace with your current kivy version !

from kivy.app import App
from kivy.config import Config

# Los configs por alguna razón solo funcionan si están puestos justo después del import de Config.

Config.set('graphics', 'width', 900)
Config.set('graphics', 'height', 600)
Config.set('graphics', 'resizable', 0)

import serial

from kivy.core.window import Window
from kivy.properties import StringProperty, NumericProperty, ObjectProperty
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.textinput import TextInput
from kivy.uix.behaviors import *
from kivy.uix.image import Image
#from kivy.graphics.instructions import Canvas
from kivy.uix.widget import Widget
from kivy.clock import Clock
from kivy.uix.slider import Slider
#from kivy.lang import Builder

#Builder.load_file('gui.kv')

ser = serial.Serial(port='COM3', baudrate=115200, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, bytesize=serial.EIGHTBITS, timeout=0)

negativo = ""
separador = ","
motor1 = ""
motor2 = ""
motor3 = ""
motor4 = ""
stepper = 0

class main(Widget):

	def __init__(self, **kwargs):
		super(main, self).__init__(**kwargs)


	def serialSend(self):
		global motor1
		global motor2
		global motor3
		global motor4
		global stepper
		global separador
		global negativo
		#---------------- Verificar si el puerto serial está abierto ----------------
		if ser.isOpen():
			pass
		else:
			ser.open()
		#----------------------------------------------------------------------------
		motor1 = self.ids.servo1.value
		motor2 = self.ids.servo2.value
		motor3 = self.ids.servo3.value
		motor4 = self.ids.servo4.value
		#stepper = 1.8*(self.ids.stepper.value.rstrip("0").rstrip(".") if "." in self.ids.stepper.value else self.ids.stepper.value)
		stepper = self.ids.stepper.value
		ser.write("<".encode())
		ser.write(str(motor1).encode())
		ser.write(separador.encode())
		ser.write(str(motor2).encode())
		ser.write(separador.encode())
		ser.write(str(motor3).encode())
		ser.write(separador.encode())
		ser.write(str(motor4).encode())
		ser.write(separador.encode())
		
		#---------------------- Código para manejar el stepper ---------------------

		if stepper < 0:
			stepper = abs(stepper)
			negativo = 1
		elif stepper > 0:
			negativo = 0

		#---------------------------------------------------------------------------

		ser.write(str(stepper).encode())
		ser.write(separador.encode())
		ser.write(str(negativo).encode())
		ser.write(">".encode())

		#-------------------------- Vacíar el buffer de salida ----------------------
		ser.flushOutput()
		#------------------------- Cerrar el puerto serial --------------------------
		ser.close()


	#def slider1(self, *args):
	#	global motor1
	#	motor1 = self.ids.servo1.value
	#	sendSerial()
	#	#print(args[1])

	#def slider2(self, *args):
	#	global motor2
	#	motor2 = args[1]
	#	print(motor2)
		#print(args[1])

	#def slider3(self, *args):
	#	global motor3
	#	motor3 = args[1]
	#	print(motor3)
	#	#print(args[1])

	#def servo4_boton_izq(event):
	#	global pos_garra
	#	global sendSerial
	#	pos_garra = pos_garra + 1
	#	print(pos_garra)
	#	sendSerial(void)
		#print(separador.encode())

	#def servo4_boton_der(event):
	#	global pos_garra
	#	pos_garra = pos_garra - 1
	#	print(pos_garra)

class GUI(App):
	def build(self):
		return main()

if __name__ == '__main__':
	GUI().run()

