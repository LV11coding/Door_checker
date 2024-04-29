# Door_checker
Check if a door is open and send the info via Bluetooth to your device. The sensor detects if a set distance(the distance to your door versus the normal distance with the closed door) is reached and sends a text message to your phone.

Needed components: Arduino(any), Ultrasonic sensor(hc-sr04), Bluetooth module(HC-06/HC-05), Jumper wires, button(pin 5) 
Needed libraries: SoftwareSerial.h
Needed Software for phone: Bluetooth Terminal(when inside terminal, make sure that "recieve data" is checked)

Connections: Ultrasonic sensor: trig-9pin, echo-10pin && Bluetooth module: RXD-4, TXD-3

Note: On line 29 you can change the distance according to your door's distance from the sensor.
Note: Uncomment code on line 28 to see the live distance the sensor is measuring.
Note: When in app, send a message firstly to activate communication between module and phone.
