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
int negativo;
int previo = 0;
int pasos = 0;

#define DIR 2
#define STEP 3

boolean datosNuevos = false;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Stepper myStepper(pasos,2,3);

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  //pinMode(4,OUTPUT);
  //pinMode(5,OUTPUT);
  servo1.attach(11, 1000, 2000);
  servo2.attach(10, 1000, 2000);
  servo3.attach(9, 1000, 2000);
  servo4.attach(6, 1000, 2000);
  myStepper.setSpeed(60);
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
    stepperWrite();
    showParsedData();
  }
  //Serial.println("Probando");
  Serial.flush();
  delay(10);
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

  token = strtok(NULL, ",");
  pasos = atoi(token);

  token = strtok(NULL, ",");
  negativo = atoi(token);
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

// --------------------------- Escribir al stepper ------------------------------
// El step angle del NEMA 14 es de 1.8° (360°/200 pasos/rev)
void stepperWrite(){  
  if (negativo == 0){
    if (pasos > previo){
      pasos = pasos - previo;
      myStepper.step(pasos);
      previo = pasos; 
    }
    else if (pasos < previo){
      pasos = previo - pasos;
      myStepper.step(-pasos);
      previo = pasos;
    }
  }
  else if (negativo == 1){
    if (pasos > previo){
      pasos = pasos - previo;
      myStepper.step(-pasos);
      previo = pasos; 
    }
    else if (pasos < previo){
      pasos = previo - pasos;
      myStepper.step(pasos);
      previo = pasos;
    }    
  }
}


// ---------------------- Escribir datos al servo para moverlos -----------------

void servoWrite(){
  primer_servo = map(primerServo, -90, 90, 0, 180);
  servo1.write(primerServo);
  segundo_servo = map(segundoServo, 0, 180, 0, 180);
  servo2.write(segundoServo);
  tercer_servo = map(tercerServo, 0, 180, 0, 180);
  servo3.write(tercerServo);
  cuarto_servo = map(cuartoServo, 0, 180, 0, 180);
  servo4.write(cuartoServo);
}
