// Movimiento de los servos.

#include <Servo.h>

const char longitud = 16;
char inData = ' ';
char index = 0;
char recibido [longitud];
char tempChars [longitud];
int primerServo;
int segundoServo;
int tercerServo;
int cuartoServo;
#define corte ','
#define inicio '<'
#define fin '>'
int giro = 0;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("Arduino conectado.");
  
  servo1.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  recibirConMarcador();
  strcpy(tempChars, recibido);
  separarDatos();
  showParsedData();
  /*if (Serial.available() > 0) {
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
  }*/
}

// ------------- Funciones adicionales -----------------------

void recibirConMarcador(){
  static boolean recibiendo = false;
  while(Serial.available() > 0){
    inData = Serial.read();
    if (recibiendo == true){
      if (inData != fin){
      recibido[index] = inData;
      index = index + 1;
      }
      if (index > longitud){
        index = longitud - 1;
      }
    }
    else{
      recibido[index] = '\0';
      index = 0;
      recibiendo = false;
    }
    if (inData == inicio){
      recibiendo = true;
    }
  }
}

void separarDatos(){
  char * token;
  token = strtok(recibido, ',');
  primerServo = atoi(token);

  token = strtok(NULL, ',');
  segundoServo = atoi(token);

  token = strtok(NULL, ',');
  tercerServo = atoi(token);

  token = strtok(NULL, ',');
  cuartoServo = atoi(token);
}


void showParsedData() {
    Serial.print("Primer servo:  ");
    Serial.println(primerServo);
    Serial.print("Segundo servo: ");
    Serial.println(segundoServo);
    Serial.print("Tercer servo: ");
    Serial.println(tercerServo);
    Serial.print("Cuarto servo: ");
    Serial.println(cuartoServo);
}
