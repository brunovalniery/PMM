#include<Servo.h>
int portaservo = 10, ang = 90, ang1 = 0, ang2 = 0, out1 = 0, out2=0, sensor =0, e, d;

Servo s;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s.attach(portaservo);
  s.write(ang);
}

void loop() {
  // put your main code here, to run repeatedly:
  ang1 = ang + 5;
  s.write(ang1);
  delay(100);
  e = analogRead(A5); //leitura do sensor de luminosidade
  
  ang2 = ang - 5;
  s.write(ang2);
  delay(100);
  d = analogRead(A5);
  
  if(d>e){
    ang = ang + 5;
    delay(100);
  }
  else{
    ang = ang -5;
    delay(100);
  }
}
