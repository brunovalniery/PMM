int lido = 0;  
float escrito = 0, imp = 0, p =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(A5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lido = analogRead(A5);
  escrito = map(lido, 0, 1023, 0, 100);
  p=20;
  
  imp = escrito/100;
  
  digitalWrite(8, HIGH);
  delay(imp*p);
  digitalWrite(8, LOW);
  delay(imp-(imp*p));
}
