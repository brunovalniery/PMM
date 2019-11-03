int ligado = 0, estado = 0; //LED
float lido = 0;  
float escrito = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  ligado = digitalRead(A0);
  lido = analogRead(A5);
  escrito = lido/4;
  Serial.println(escrito);
  delay(100); //corrigir bouncing
  analogWrite(10, escrito);
  
  if (estado == 0 && ligado == 0) {
    lido = 0;
    digitalWrite(10, LOW);
    estado = 1;
    ligado = 1;
    delay(100);
  }
  if (estado == 1 && ligado == 1) {
    estado = 0;
    delay(100);
   }
  
}
