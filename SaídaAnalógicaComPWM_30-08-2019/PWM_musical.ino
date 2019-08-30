char notes[] = "ddaabbaggkkeed ";
int beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2};
int tempo = 400;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT); //deve ser utilizado uma porta que possua um '~' (3, 5, 6, 9, 10, e 11 são portas PWM).
  Serial.begin(9600);
}

void loop() {
  int tamanho = sizeof(notes)/sizeof(notes[0]);
  
  // put your main code here, to run repeatedly:
  for (int i = 0; i < tamanho; i++) {
    if (notes[i] == 'c') {
      tone(9, 261, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    if (notes[i] == 'l') {//Dó#
      tone(9, 278, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    
    if (notes[i] == 'd') {
      tone(9, 294, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    if (notes[i] == 'e') {
      tone(9, 329, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    if (notes[i] == 'f') {
      tone(9, 349, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    if (notes[i] == 'k') {//Fá#
      tone(9, 370, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    if (notes[i] == 'g') {
      tone(9, 392, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    if (notes[i] == 'a') {
      tone(9, 440, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    if (notes[i] == 'b') {
      tone(9, 493, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
    if (notes[i] == ' ') {
      tone(9, 0, beats[i]*tempo);
      delay(beats[i]*tempo);
      Serial.println(beats[i]);
    }
  }
}
