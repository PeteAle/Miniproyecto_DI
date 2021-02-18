// Movimiento de los servos.

#include <Servo.h>
#include <Stepper.h>

const byte longitud = 32;
char recibido [longitud];
char tempChars [longitud];

char inData;
char indice = 0;
static boolean recibiendo = false;
char inicio = '<';
char fin = '>';

int primerServo;  int primer_servo;
int segundoServo; int segundo_servo;
int tercerServo;  int tercer_servo;
int cuartoServo;  int cuarto_servo;

boolean datosNuevos = false;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(11, 1000, 2000);
  servo2.attach(10, 1000, 2000);
  servo3.attach(9, 1000, 2000);
  servo4.attach(6, 1000, 2000);
  Serial.begin(115200);
  Serial.println("Arduino conectado.");

}

void loop() {
  // put your main code here, to run repeatedly:
  recibirConMarcador();
  if (datosNuevos == true){
    strcpy(tempChars, recibido);
    separarDatos();
    datosNuevos = false;
    servoWrite();
    showParsedData();
  }
  //Serial.println("Probando");
  delay(100);
}

// ------------------ Recibir los datos y guardalos -----------------------

void recibirConMarcador(){
    
  while(Serial.available() > 0 && datosNuevos == false){
    inData = Serial.read();
    if (recibiendo == true){
      if (inData != fin){
        recibido[indice] = inData;
        indice++;
        if (indice > longitud){
          indice = longitud - 1;
        }
      }
       else{
        recibido[indice] = '\0';
        indice = 0;
        recibiendo = false;
        datosNuevos = true;
      }
    }
    else if (inData == inicio){
      recibiendo = true;
    }
  }
}

// ------------------------ Separar los datos en el arduino -------------------

void separarDatos(){
  char * token;
  
  token = strtok(recibido, ",");
  primerServo = atoi(token);

  token = strtok(NULL, ",");
  segundoServo = atoi(token);

  token = strtok(NULL, ",");
  tercerServo = atoi(token);

  token = strtok(NULL, ",");
  cuartoServo = atoi(token);
}

// ------------------ Mostrar datos en el monitor -------------------

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

// ---------------------- Escribir datos al servo para moverlos -----------------

void servoWrite(){
  primer_servo = map(primerServo, 0, 180, 0, 180);
  servo1.write(primerServo);
  segundo_servo = map(segundoServo, 0, 180, 0, 180);
  servo2.write(segundoServo);
  tercer_servo = map(tercerServo, 0, 180, 0, 180);
  servo3.write(tercerServo);
  cuarto_servo = map(cuartoServo, 0, 180, 0, 180);
  servo4.write(cuartoServo);
}
