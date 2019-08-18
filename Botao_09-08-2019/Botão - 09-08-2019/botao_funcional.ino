int ligado = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //LED BUILTIN
  pinMode(3, INPUT_PULLUP); //Botão que utiliza o resistor do LED_BUILTIN
}
void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(3) && !ligado) {
    digitalWrite(13, HIGH);
    ligado = 1;
    delay(500);
  }
  if (!digitalRead(3) && ligado) {
    digitalWrite(13, LOW);
    ligado = 0;
    delay(500);
  }
}
