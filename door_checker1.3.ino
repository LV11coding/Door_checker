#define trig 10
#define echo 9
#define button 5

#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C disp(0x27, 16, 2);

SoftwareSerial bl(3, 4);

int dis = 0;
int long dur = 0;
int disminus = 0;
int displus = 0;
int mode = 0;
int previous = 0;
bool sup = false;
String modetext = "Ruler";
const String text0 = "Checking distance.";
const String text = "The distance chenged.";
const String text1 = "The distance hasn't changed.";
const String text2 = "Not checking distance.";

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(button, INPUT);
  //Serial.begin(9600);
  bl.begin(9600);
  disp.init();
  disp.backlight();
  disp.setCursor(1, 0);
  disp.print("Smart ruler");
  delay(2500);
  disp.clear();
}

void loop() {
  previous = dis;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dis = dur * 0.034 / 2;
  //Serial.print("Distance: ");
  //Serial.println(dis);
  disp.setCursor(1, 0);
  disp.print("Mode: ");
  disp.print(modetext);
  disp.setCursor(1, 1);
  disp.print("Distance: ");
  disp.print(dis);
  disp.print("cm");
  if (bl.available()) {
    bl.println(dis);
    while (digitalRead(button) == HIGH) {
      modetext = "ChDisCh";
      disp.clear();
      disp.setCursor(1, 0);
      disp.print("Mode: ");
      disp.print(modetext);
      if (sup == false) {
        disminus = dis - 10;
        displus = dis + 10;
        sup = true;
      }
      disp.setCursor(1, 1);
      disp.print(disminus);
      disp.print(";");
      disp.print(dis);
      disp.print(";");
      disp.print(displus);
      disp.print(";");
      bl.println(text0);
      if (dis < displus && dis > disminus) {  //example: 100<110 and 100>90
        bl.println(text1);
      }
      if (dis >= displus || dis <= disminus) { //example: 100 > 110 or 100 < 90
        bl.println(text);
        disp.setCursor(0, 1);
        disp.print("The distance changed");
      }
    }
    if (previous != dis) {
      disp.clear();
    }
    modetext = "Ruler";
  }
  delay(100);
}
