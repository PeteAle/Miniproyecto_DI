
int pinPaso = ;
int pinDir = ;
int datoEntrante = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinPaso, OUTPUT);
  pinMode(pinDir, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0){
    datoEntrante = Serial.read();
  }
}
