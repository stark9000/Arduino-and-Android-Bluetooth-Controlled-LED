#include <SoftwareSerial.h> //including the software serial library.
SoftwareSerial btm(3, 2); // rx tx // initiating software serial object.
char c;
int LED = 4;

void setup() {
  btm.begin(9600);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (btm.available() > 0) {
    while (btm.available() > 0) {
      c = btm.read();
      Serial.println(c);
      if (c == '1') {
        Serial.println("on");
        digitalWrite(LED, HIGH);
      } else if (c == '0') {
        Serial.println("off");
        digitalWrite(LED, LOW);
      }
    }
  }
}
