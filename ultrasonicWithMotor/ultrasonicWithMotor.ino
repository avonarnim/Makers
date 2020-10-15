#include <Servo.h>
#include <NewPing.h>

#define maxDist 400

const int trigPin = 12;
const int echoPin = 11;
const int servoPin = 9;
const int thresh = 10;
int angle = 90;

NewPing sonar(trigPin, echoPin, maxDist);
Servo s;

void setup() {
  Serial.begin(9600);
  s.attach(servoPin);
  s.write(angle);
}

void loop() {
  int dist = sonar.ping_cm();
  if (dist > 0 && dist < thresh) {
    if (angle != 180) {
      angle += 5;
    }
  } else {
    if (angle != 0) {
      angle -= 5;
    }
  }
  s.write(angle);
  Serial.print("Servo Angle: ");
  Serial.println(angle);
}
