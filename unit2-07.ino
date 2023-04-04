/*
  Created by Cristiano S
  Created in April 2023

  Uses a distance sensor to control whenever a servo moves
*/

#include <Servo.h>

int trigPin = 2;
int echoPin = 3;
float duration, distance;
Servo servo;

void setup()
{
  pinMode(trigPin, OUTPUT); // Set trigPin as an output
  pinMode(echoPin, INPUT);  // Set echoPin as an input
  Serial.begin(9600);       // Begin the serial monitor at 9600
  servo.attach(4);          // Attach servo signal to pin 4
  servo.write(0);           // Set servo to 0 degrees
  delay(1000);              // Wait for 1000 millisecond(s)
}

void loop()
{
  digitalWrite(trigPin, LOW);  // Send a low signal to the trig pin 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Send a high signal to the trig pin 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Receive the signal
  distance = (duration*.0343) / 2;   // Calculate distance
  // Print to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
  // Move the servo if distance is less than 50 cm
  if (distance < 50) {
    Serial.println("Servo start");
    servo.write(180);
    delay(1000);
    servo.write(0);
    delay(1000);
  }
}
