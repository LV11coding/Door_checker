#define trig 10
#define echo 9
#include <SoftwareSerial.h>
SoftwareSerial bl (3, 4);

int dis = 0;
int long dur = 0;
String text = "The door has opened.";

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  //Serial.begin(9600);
  bl.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dis = dur * 0.034 / 2;
  //Serial.print("Distance: ");
  //Serial.println(dis);
  if (bl.available()) {
    //bl.println(dis);
    if (dis < 110 || dis > 180) {
      bl.println(text);
    }
  }
  delay(100);
}
