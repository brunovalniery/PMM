int lido = 0;  
float escrito = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lido = analogRead(A5);
  escrito = lido/4;
  Serial.println(escrito);
  delay(100); //corrigir bouncing
}
