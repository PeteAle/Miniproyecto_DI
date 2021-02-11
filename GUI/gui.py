import kivy
kivy.require('2.0.0') # replace with your current kivy version !

from kivy.app import App
from kivy.config import Config

# Los configs por alguna razón solo funcionan si están puestos justo después del import de Config.

Config.set('graphics', 'width', 800)
Config.set('graphics', 'height', 600)
Config.set('graphics', 'resizable', 0)

#from kivy.core.window import Window
from kivy.properties import StringProperty, NumericProperty, ObjectProperty, ListProperty
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.textinput import TextInput
from kivy.uix.behaviors import *
from kivy.uix.image import Image
from kivy.uix.widget import Widget
from kivy.clock import Clock
from kivy.lang import Builder

Builder.load_file('gui.kv')

class main(Widget):
	def __init__(self, **kwargs):
		super(main, self).__init__(**kwargs)

	def servo1_boton_izq():
		pass

	def servo1_boton_der():
		pass

	def servo2_boton_izq():
		pass

	def servo2_boton_der():
		pass

	def servo3_boton_izq():
		pass

	def servo3_boton_der():
		pass

	def servo4_boton_izq():
		pass

	def servo4_boton_der():
		pass


class GUI(App):
	def build(self):
		return main()

if __name__ == '__main__':
	GUI().run()

