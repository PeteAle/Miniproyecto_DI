int pasos = 200;

const int boton = 4;
const int dir = 7;
const int STEP = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir,HIGH);
  for (int i = 0; i < pasos ; i++){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  digitalWrite(dir,LOW);
  for (int i = 0; i < pasos ; i++){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
