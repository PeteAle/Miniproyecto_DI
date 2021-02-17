import kivy
kivy.require('2.0.0') # replace with your current kivy version !

from kivy.app import App
from kivy.config import Config

# Los configs por alguna razón solo funcionan si están puestos justo después del import de Config.

Config.set('graphics', 'width', 800)
Config.set('graphics', 'height', 600)
Config.set('graphics', 'resizable', 0)

import serial

#from kivy.core.window import Window
from kivy.properties import StringProperty, NumericProperty, ObjectProperty, ListProperty
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.textinput import TextInput
from kivy.uix.behaviors import *
from kivy.uix.image import Image
from kivy.graphics.instructions import Canvas
from kivy.uix.widget import Widget
from kivy.clock import Clock
from kivy.uix.slider import Slider
from kivy.lang import Builder

#Builder.load_file('gui.kv')

pos_garra = 90;

class main(Widget):
	def __init__(self, **kwargs):
		super(main, self).__init__(**kwargs)

	def slider1(self, *args):
		print(args[1])

	def slider2(self, *args):
		print(args)

	def slider3(self, *args):
		print(args)

	def servo4_boton_izq(event):
		global pos_garra
		pos_garra = pos_garra + 1
		print(pos_garra)

	def servo4_boton_der(self, pos_garra):
		pos_garra = pos_garra - 1
		print(pos_garra)

class GUI(App):
	def build(self):
		return main()

if __name__ == '__main__':
	GUI().run()

