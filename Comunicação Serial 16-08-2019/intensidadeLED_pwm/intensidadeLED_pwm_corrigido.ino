void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(10, OUTPUT);
  pinMode(7, INPUT_PULLUP);

}
int valorLido;
int valorEscrito;
int led = 0;

void loop() {
  valorLido = analogRead(A5);
  valorEscrito = map (valorLido, 0, 1023, 0, 255);
  Serial.println(valorEscrito);
  if (valorEscrito - led < 0) {

    analogWrite(10, 0);
  } else {
    analogWrite(10, valorEscrito - led);
  }
  if (digitalRead(7) == LOW) {
    Serial.println("valor");
    led = valorEscrito;
    // valorEscrito=0;
    delay(150);
  }
  Serial.println(led);
  

}
