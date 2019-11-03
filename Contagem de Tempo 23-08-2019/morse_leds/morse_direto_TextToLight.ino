int aux = 1;
int aux2 = 1;
int estado = 0;
int i = 0;
int botao;
int estado2=0;

unsigned long tempoLed;
char vogais[5];
void setup() {
  pinMode (12, OUTPUT);
  pinMode (8, INPUT_PULLUP);
  Serial.begin(9600);

}

void curto() {
  while (aux == 1) {
    if (estado == 0) {
      digitalWrite(12, HIGH);
      tempoLed = millis();
      estado = 1;
    }
    if (estado == 1 && millis() > tempoLed + 100) {
      digitalWrite(12, LOW);
      estado = 2;
      tempoLed = millis();
    }
    if (estado == 2 && millis() > tempoLed + 100) {
      aux = 0;
    }
  }

} //Fim do curto
void longo() {
  while (aux2 == 1) {
    if (estado == 0) {
      digitalWrite(12, HIGH);
      estado = 1;
      tempoLed = millis();
    }
    if (estado == 1 && millis() > tempoLed + 300) {
      digitalWrite(12, LOW);
      estado = 2;
      tempoLed = millis();
    }
    if (estado == 2 && millis() > tempoLed + 100) {
      aux2 = 0;
    }
  }
}//Fim do Longo

void loop() {
  botao = digitalRead(8);
  

    if ((botao == 0)&&(estado2 == 0)) {
      Serial.readBytes(vogais, 5);
      for (i; i < 6; i++) {
      
      aux = 1;
      aux2 = 1;
      
        if (vogais[i] == 'a' || vogais[i] == 'A') {
          curto();
          estado = 0;
          longo();
          estado = 0;
        }
        if (vogais[i] == 'e' || vogais[i] == 'E') {
          curto();
          estado = 0;
        }
        if (vogais[i] == 'i' || vogais[i] == 'I') {
          curto();
          estado = 0;
          aux = 1;
          curto();
          estado = 0;
        }
        if (vogais[i] == 'o' || vogais[i] == 'O') {
          longo();
          estado = 0;
          aux2 = 1;
          longo();
          estado = 0;
          aux2 = 1;
          longo();
          estado = 0;
        }
        if (vogais[i] == 'u' || vogais[i] == 'U') {
          curto();
          aux = 1;
          estado = 0;
          curto();
          aux = 1;
          estado = 0;
          longo();
          estado = 0;
        }
        delay(2000);
        Serial.print("valor do i: ");
        Serial.println(i);
      }
      estado2 = 1;
    }
    if ((estado2 == 1) && (botao == 1)) {
      estado2 = 0;
      i = 0;
    }
  //}

}
