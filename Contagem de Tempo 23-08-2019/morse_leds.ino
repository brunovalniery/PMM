int tecla = 0, estado = 1, botao = 0;
unsigned long time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  time = millis();
  tecla = Serial.read();
  
  
  if((millis()>time+100 && tecla == 'A' && estado == 1) || (millis()>=time+100 && tecla == 'a' && estado == 1)){  
    digitalWrite(13, HIGH);
    estado = 2;
    delay(50);
    time = millis();
  }
/*
  if((millis()>time+50 && tecla == 'A' && estado == 2) || (millis()>=time+50 && tecla == 'a' && estado == 2)){
    estado = 3;
    delay(50);
  }
  */
  if((millis()>time+50 && tecla == 'A' && estado == 2) || (millis()>=time+50 && tecla == 'a' && estado == 2)){
    digitalWrite(13, LOW);
    estado = 3;
    delay(50);
    time = millis();
  }
/*
  if((millis()>time+100 && tecla == 'A' && estado == 4) || (millis()>=time+100 && tecla == 'a' && estado == 4)){
    estado = 5;
    delay(50);
  }
*/
  if((millis()>time+300 && tecla == 'A' && estado == 3) || (millis()>=time+300 && tecla == 'a' && estado == 3)){
    digitalWrite(13, HIGH);
    delay(50);
    estado = 1;
    time = millis();
  }
/*
  if((millis()>time+50 && tecla == 'A' && estado == 6) || (millis()>=time+50 && tecla == 'a' && estado == 6)){
    digitalWrite(13, LOW);
    estado = 1;
  }
*/  
}
