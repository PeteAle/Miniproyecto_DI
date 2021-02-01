import kivy
kivy.require('2.0.0') # replace with your current kivy version !

from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.uix.boxlayout import BoxLayout
from kivy.properties import StringProperty, NumericProperty, ObjectProperty, ListProperty
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.textinput import TextInput
from kivy.uix.image import Image
from kivy.config import Config
from kivy.uix.widget import Widget
from kivy.core.window import Window
from kivy.clock import Clock

Config.set('graphics', 'width', 640)
Config.set('graphics', 'height', 640)

class main(Widget):
	def __init__(self, **kwargs):
		super(main, self).__init__(**kwargs)

class GUI(App):
	def build(self):
		return main()

if __name__ == '__main__':
	GUI().run()

