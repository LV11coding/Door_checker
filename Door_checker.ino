

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
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(button, INPUT);
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
    bl.println(dis);
    if (digitalRead(button) == HIGH) {
      disminus = dis - 10;
      displus = dis + 10;
      bl.println(text0);
      if (dis < displus && dis > disminus) {  //example: 100<110 and 100>90
        bl.println(text1);
      } else {
        bl.println(text); //PROBLEM, PROBLEM, PROBLEM
      }
    }
    delay(100);
  }
}