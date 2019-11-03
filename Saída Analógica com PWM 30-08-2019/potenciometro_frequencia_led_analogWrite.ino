int lido = 0;  
float escrito = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT); //deve ser utilizado uma porta que possua um '~' (3, 5, 6, 9, 10, e 11 são portas PWM).
  pinMode(A5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lido = analogRead(A5);
  escrito = map(lido, 0, 1023, 0, 255);
  analogWrite(9, escrito);
}
