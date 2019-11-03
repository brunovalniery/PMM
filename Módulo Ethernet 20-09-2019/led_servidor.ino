#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
EthernetServer server(80);

int lido = 0;
float escrito = 0;

void setup() {
  pinMode(2, OUTPUT); //LED BUILTIN
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
        }

        if (c == 0x0D) {
          delay(10);
          // control arduino pin
          if (readString.indexOf("botao=0")>-1) { //checks for LEDON
            digitalWrite(2, HIGH)
          }
        }
      }
      // give the web browser time to receive the data
      delay(1);
      // close the connection:
      client.stop();
      Serial.println("client disconnected");
    }


    if (!digitalRead(3) && !ligado) {
      digitalWrite(2, HIGH);
      ligado = 1;
      delay(500);
    }
    if (!digitalRead(3) && ligado) {
      digitalWrite(13, LOW);
      ligado = 0;
      delay(500);
    }

    lido = analogRead(A5);
    escrito = map(lido, 0, 1023, 0, 255);
    analogWrite(9, escrito);


  }
