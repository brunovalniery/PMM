int estado = 0,  apertado = digitalRead(3);

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //LED BUILTIN
  pinMode(3, INPUT_PULLUP); //Botão que utiliza o resistor do LED_BUILTIN
}
void loop() {
  // put your main code here, to run repeatedly:
  if (estado == 0 && apertado == 0){
    digitalWrite(13, HIGH);
    estado = 1;
    delay(100); //corrigir boucing
  }
  if(estado == 1 && apertado == 1){
    digitalWrite(13, LOW);
    estado = 2;
    delay(100); //corrigir boucing
  }
  if(estado == 2 && apertado == 0){
    digitalWrite(13, HIGH);
    estado = 3;
    delay(100); //corrigir boucing
  }
  if(estado == 3 && apertado == 1){
    digitalWrite(13, LOW);
    estado = 0;
    delay(100); //corrigir boucing
  }
  apertado = digitalRead(3);
}
