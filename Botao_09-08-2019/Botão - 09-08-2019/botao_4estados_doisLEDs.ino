int estado = 0;
int apertado = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //LED BUILTIN
  pinMode(12, OUTPUT); //LED BUILTIN
  pinMode(3, INPUT_PULLUP); //Botão que utiliza o resistor do LED_BUILTIN
}
void loop() {
  apertado = digitalRead(3);
  // put your main code here, to run repeatedly:
  if (estado == 0 && apertado == 0){
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    estado = 1;
    delay(100); //corrigir bouncing
  }
  if(estado == 1 && apertado == 1){
    estado = 2;
    delay(100); //corrigir bouncing
  }
  if(estado == 2 && apertado == 0){
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    estado = 3;
    delay(100); //corrigir bouncing
  }
  if(estado == 3 && apertado == 1){
    estado = 4;
    delay(100); //corrigir bouncing
  }
  if(estado == 4 && apertado == 0){
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    estado = 5;
    delay(100); //corrigir bouncing
  }
  if(estado == 5 && apertado == 1){
    estado = 6;
    delay(100); //corrigir bouncing
  }
  if(estado == 6 && apertado == 0){
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    estado = 7;
    delay(100); //corrigir bouncing
  }
  if(estado == 7 && apertado == 1){
    estado = 8;
    delay(100); //corrigir bouncing
  }
  if(estado == 8 && apertado == 1){
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    estado = 9;
    delay(100); //corrigir bouncing
  }
  if(estado == 9 && apertado == 0){
    estado = 0;
    delay(100); //corrigir bouncing
  }

}
