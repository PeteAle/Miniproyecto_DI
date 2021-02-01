import kivy
kivy.require('2.0.0') # replace with your current kivy version !

from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.label import Label
from kivy.uix.button import Button
# from kivy.graphics import *
from kivy.uix.textinput import TextInput
from kivy.uix.image import Image
from kivy.config import Config
from kivy.lang import Builder
from kivy.core.window import Window

#class layout(GridLayout):
	# Inicializar los keywords
#	def __init__(self, **kwargs):
		# Construir el layout del grid.
#		super(layout, self).__init__(**kwargs)

#		# Setear columnas
#		self.cols = 2
#		# Agregar widgets
#		self.add_widget(Label(text='Ángulo: '))
#		self.angulo = TextInput(multiline=False)
#		self.add_widget(self.angulo)

class interfaz(FloatLayout):
	def __init__(self, **kwargs): 
		super(interfaz, self).__init__(**kwargs)


class MyApp(App):
	def build(self):
		#Window.clearcolor = (1,1,1,1)
		layout = FloatLayout(size=(800,800))

		layout.add_widget(Label(text='[font=Micross][b]GUI de control del brazo[/b][/font]', markup=True,
			font_size=32,
			size_hint_y=None,
			height=40,
			size_hint_x=None,
			width=400, 
			pos_hint={'center_x':0.5,'center_y':0.95}))

		# Lo títulos para cada uno de los servos y el stepper a utilizar.

		layout.add_widget(Label(text='[b]Servo de giro: [/b]', markup=True,
			font_size=20,
			pos_hint={'center_x':0.25,'center_y':0.6}))

		layout.add_widget(Label(text='[b]Servo de base: [/b]', markup=True,
			font_size=20,
			pos_hint={'center_x':0.5,'center_y':0.6}))

		layout.add_widget(Label(text='[b]Primera articulación: [/b]', markup=True,
			font_size=20,
			pos_hint={'center_x':0.75,'center_y':0.6}))

		layout.add_widget(Label(text='[b]Segunda articulación: [/b]', markup=True,
			font_size=20,
			pos_hint={'center_x':0.33,'center_y':0.2}))

		layout.add_widget(Label(text='[b]Stepper de motor: [/b]', markup=True,
			font_size=20,
			pos_hint={'center_x':0.66,'center_y':0.2}))

		# Imágenes representativas de la articulación del brazo que dichos servos y el stepper van a mover.

		layout.add_widget(Image(source='Niryo_prueba.png',
			size_hint=(None,None),
			size=(150,150),
			pos_hint={'center_x':0.25,'center_y':0.75}))

		layout.add_widget(Image(source='Niryo_prueba.png',
			size_hint=(None,None),
			size=(150,150),
			pos_hint={'center_x':0.5,'center_y':0.75}))

		layout.add_widget(Image(source='Niryo_prueba.png',
			size_hint=(None,None),
			size=(150,150),
			pos_hint={'center_x':0.75,'center_y':0.75}))

		layout.add_widget(Image(source='Niryo_prueba.png',
			size_hint=(None,None),
			size=(150,150),
			pos_hint={'center_x':0.33,'center_y':0.35}))

		layout.add_widget(Image(source='Niryo_prueba.png',
			size_hint=(None,None),
			size=(150,150),
			pos_hint={'center_x':0.66,'center_y':0.35}))

		# Botones de movimiento.

		#layout.add_widget(Button(text='Enviar',
		#	font_size=18,
		#	size_hint=(None,None),
		#	size=(90,30),
		#	pos_hint={'center_x':0.15,'center_y':0.54}))

		layout.add_widget(Button(text='',
			background_normal='rotar.png',
			background_down='Niryo_prueba.png',
			size_hint=(0.05,0.1),
			#size=(64,46),
			pos_hint={'center_x':0.15,'center_y':0.54}))

		return interfaz()

if __name__ == '__main__':
    MyApp().run()