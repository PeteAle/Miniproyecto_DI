// Movimiento de los servos.

#include <Servo.h>

int boton_inc = 8;  // Botón para incrementar el valor del servo (movimiento derecho).
int boton_dec = 7;  // Botón para decrementar el valor del servo (movimiento izquierdo).
int press_inc = 0;  // Variable de estado del botón de incremento.
int press_dec = 0;  // Variable de estado del botón de decremento.
int giro = 90;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servoMotor.attach(9);
  pinMode(boton_inc, INPUT);
  pinMode(boton_dec, INPUT);
  digitalWrite(boton_inc, HIGH);
  digitalWrite(boton_dec, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  press_inc = digitalRead(boton_inc);
  if (press_inc == LOW){
    servo1.write(++giro);
  }
  press_dec = digitalRead(boton_dec)
  if (press_dec == LOW){
    servo1.write(--giro);
  }
}
