int estado = 1, botao = 0;
unsigned long time;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(10, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  botao = digitalRead(10);
  
  if(botao == 0 && estado == 1){
    time = millis();
    digitalWrite(13, HIGH);
    estado = 2;
    delay(200);
  }

  if(botao == 0 && estado == 2){
    //digitalWrite(13, LOW);
    estado = 3;
    delay(200);
  }
  if((millis()>=time+3000 && estado == 3)||(botao == 0 && estado == 2)){
    digitalWrite(13, LOW);
    estado = 1;
    delay(200);
  }
}
