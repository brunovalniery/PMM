int apertado = 0, estado = 0;
int c = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  apertado = digitalRead(A0);
  if (estado == 0 && apertado == 0) {
    estado = 1;
    c = c + 1;
    delay(100); //corrigir bouncing
  }
  if (estado == 1 && apertado == 1) {
    Serial.print("Pressionado: ");
    Serial.println(c);
    estado = 0;
    delay(100); //corrigir bouncing
  }
  delay(50);
}
