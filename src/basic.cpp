
/* Stepper Copal
* -------------
*
* Program to drive a stepper motor coming from a 5'25 disk drive
* according to the documentation I found, this stepper: "[...] motor
* made by Copal Electronics, with 1.8 degrees per step and 96 ohms
* per winding, with center taps brought out to separate leads [...]"
* [http://www.cs.uiowa.edu/~jones/step/example.html]
*
* It is a unipolar stepper motor with 5 wires:
*
* - red: power connector, I have it at 5V and works fine
* - orange and black: coil 1
* - brown and yellow: coil 2
*
* (cleft) 2005 DojoDave for K3
* http://www.0j0.org | http://arduino.berlios.de
*
* @author: David Cuartielles
* @date: 20 Oct. 2005
*/
#include "Arduino.h"

int motorPins[] = {0, 8, 9, 10, 11};

int count = 0;
int count2 = 0;
int delayTime = 20;


void setup()
{
  Serial.begin(115200);
  pinMode(3, INPUT);
  pinMode(motorPins[1], OUTPUT);
  pinMode(motorPins[2], OUTPUT);
  pinMode(motorPins[3], OUTPUT);
  pinMode(motorPins[4], OUTPUT);
}



void loop()
{
  digitalWrite(motorPins[1], HIGH);
  digitalWrite(motorPins[2], LOW);
  digitalWrite(motorPins[3], LOW);
  digitalWrite(motorPins[4], LOW);
  delay(delayTime);
  digitalWrite(motorPins[1], LOW);
  digitalWrite(motorPins[2], HIGH);
  digitalWrite(motorPins[3], LOW);
  digitalWrite(motorPins[4], LOW);
  delay(delayTime);
  digitalWrite(motorPins[1], LOW);
  digitalWrite(motorPins[2], LOW);
  digitalWrite(motorPins[3], HIGH);
  digitalWrite(motorPins[4], LOW);
  delay(delayTime);
  digitalWrite(motorPins[1], LOW);
  digitalWrite(motorPins[2], LOW);
  digitalWrite(motorPins[3], LOW);
  digitalWrite(motorPins[4], HIGH);
  delay(delayTime);
  Serial.println(analogRead(0));
    //  moveBackward();

}
