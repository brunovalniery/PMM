int apertadotec = 0, apertadobut = 0, estadobut = 0, estadotec = 0;
int c = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  apertadotec = Serial.read();
  apertadobut = digitalRead(A0);
  
  if ((estadotec == 0 && apertadotec == 'r' ) || (estadotec == 0 &&  apertadotec == 'R')) {
    estadotec = 1;
    digitalWrite(13, HIGH);
    delay(1000); //corrigir bouncing
    //digitalWrite(13, LOW);
    c = 0;
  }
  if ((estadotec == 1 && apertadotec == 'r' ) || (estadotec == 1 && apertadotec == 'R')){
    digitalWrite(13, LOW);
    estadotec = 0;
  }

  if (estadobut == 0 && apertadobut == 0) {
    estadobut = 1;
    c = c + 1;
    delay(100); //corrigir bouncing
  }
  if (estadobut == 1 && apertadobut == 1) {
    Serial.print("Pressionado: ");
    Serial.println(c);
    estadobut = 0;
    delay(100); //corrigir bouncing
  }
  
  delay(50);
}
