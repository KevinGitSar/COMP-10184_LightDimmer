#include <Arduino.h>
// "StAuth10184-01: I Kevin Sar, 000390567 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else."


bool onOff = false;

void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal;
  int iButton;
  
 
  // read digitized value
  iVal = analogRead(A0);
  // read the push button input... 
  iButton = digitalRead(D5);

  // On/Off Button Switch statements
  if(iButton == LOW && onOff == true){
    onOff = false;
  } else if(iButton == LOW && onOff == false){
    onOff = true;
  }

  // If On use resistor to dim/turn on light
  // If Off the light will be off completely
  if(onOff == true){
    analogWrite(D4, iVal);
  } else if(onOff == false){
    digitalWrite(D4, HIGH);
  }
  
  // Test to check onOff Flag 
  // Serial.println(onOff);
  
  // Debounce
  delay(1);
}