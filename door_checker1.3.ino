#define trig 10
#define echo 9
#define button 5

#include <SoftwareSerial.h>
SoftwareSerial bl(3, 4);

int dis = 0;
int long dur = 0;
int disminus = 0;
int displus = 0;
bool sup = false;
const String text0 = "Checking distance.";
const String text = "YOOOOOOOOOOOOOOOOOOOOOOOOOO.";
const String text1 = "The distance hasn't changed.";
const String text2 = "Not checking distance.";

void setup() {
  pinMode(button, INPUT);
  //Serial.begin(9600);
  bl.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  dis = dur * 0.034 / 2;
  //Serial.print("Distance: ");
  //Serial.println(dis);
  if (bl.available()) {
    bl.println(dis);
    if (digitalRead(button) == HIGH) {
      if (sup == false) {
        disminus = dis - 10;
        displus = dis + 10;
        sup = true;
      }
      if (dis < displus && dis > disminus) {  //example: 100<110 and 100>90
        bl.println(text1);
      }
      if (dis >= displus || dis <= disminus) { //example: 100 > 110 or 100 < 90
        bl.println(text);
      }
    }
  }
  delay(100);
}
