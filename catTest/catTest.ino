/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob

 Modified by Amelia Tziougras February 10 2021
*/

#include <Servo.h>


Servo myservo;  // create servo object to control a servo


int val;   


void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object


}

void loop() {
         
  val = random (30, 180);     // chooses a random value between 30 and 180 to set the servo to
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(35); // waits for the servo to get there
  Serial.println(val);



}
