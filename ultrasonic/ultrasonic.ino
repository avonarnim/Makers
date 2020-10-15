#include <Servo.h>
#include <NewPing.h>

const int servoPin = 9;
const int trigPin = 12;
const int echoPin = 11;
const int maxDist = 400;

int distance;

Servo s;
NewPing sonar(trigPin, echoPin, maxDist);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void sendPacket(int angle, int distance) {
  Serial.print(angle);
  Serial.print(",");
  Serial.println(distance);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 1800; i++) {
    s.write(i);
    delay(15);
    distance = sonar.ping_cm();
    sendPacket(i, distance);
  }
  for (int i = 179; i = 1; i--) {
    s.write(i);
    delay(15);
    distance = sonar.ping_cm();
    sendPacket(i, distance);
  }
}
