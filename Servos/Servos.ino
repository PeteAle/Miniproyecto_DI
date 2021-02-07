// Movimiento de los servos.

#include <Servo.h>

const byte longitud = 32;
char recibido [longitud];
char tempChars [longitud];

char inData;
char indice = 0;
static boolean recibiendo = false;
char inicio = '<';
char fin = '>';

int primerServo;
int segundoServo;
int tercerServo;
int cuartoServo;

boolean datosNuevos = false;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  Serial.begin(115200);
  Serial.println("Arduino conectado.");

}

void loop() {
  // put your main code here, to run repeatedly:
  recibirConMarcador();
  if (datosNuevos == true){
    strcpy(tempChars, recibido);
    separarDatos();
    showParsedData();
    datosNuevos = false;
  }
}

// ------------------ Recibir los datos y guardalos -----------------------

void recibirConMarcador(){
    
  while(Serial.available() > 0 && datosNuevos == false){
    inData = Serial.read();
    if (recibiendo == true){
      if (inData != fin){
        recibido[indice] = inData;
        indice++;
        if (indice >= longitud){
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
