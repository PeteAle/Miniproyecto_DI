// Movimiento de los servos.

#include <Servo.h>

const char longitud = 5;
char inData = ' ';
char index = 0;
char recibido [longitud];
int primerServo;
int segundoServo;
#define corte ','
int boton_inc = 8;  // Botón para incrementar el valor del servo (movimiento derecho).
int boton_dec = 7;  // Botón para decrementar el valor del servo (movimiento izquierdo).
int press_inc = 0;  // Variable de estado del botón de incremento.
int press_dec = 0;  // Variable de estado del botón de decremento.
int giro = 0;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(230400);

  Serial.println("Arduino conectado.");
  
  servo1.attach(9);
  pinMode(boton_inc, INPUT);
  pinMode(boton_dec, INPUT);
  digitalWrite(boton_inc, HIGH);
  digitalWrite(boton_dec, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // read the incoming byte:   
    inData = Serial.read();
    if (inData != corte){
      recibido[index] = inData;
      index = index + 1;
      if (index > longitud){
        index = longitud - 1;
      }
    }
    else if (inData == corte){
      recibido[index] = '\0';
      index = 0;
      primerServo = atoi(recibido);
      segundoServo = atoi(recibido);
    }
    Serial.print("Primer servo: ");
    Serial.println(primerServo);
    Serial.print("Segundo servo: ");
    Serial.println(segundoServo);
    servo1.write(primerServo);
    delay(15);
  }
  /*press_inc = digitalRead(boton_inc);
  if (press_inc == LOW){
    giro = giro + 1;
    servo1.write(giro);
    delay(15);
  }
  press_dec = digitalRead(boton_dec);
  if (press_dec == LOW){
    giro = giro - 1;
    servo1.write(giro);
    delay(15);
  }*/
}
