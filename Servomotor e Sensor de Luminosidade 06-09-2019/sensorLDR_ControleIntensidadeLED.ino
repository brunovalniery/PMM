int p, sensor = 0, out, escrito;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor = analogRead(A5); 
  Serial.println(sensor);
  //analogWrite(10, 255-(sensor/4));
  //delay(200);  

  escrito = map(sensor, 0, 1023, 0, 100);
  p=20;
  
  out = escrito/100;
  
  analogWrite(8, HIGH);
  delay(out-(out*p));
  analogWrite(8, LOW);
  delay(out*p);
}
