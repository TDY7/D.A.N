#include <Servo.h>

Servo servo;

int LedRouge = 13;
int trigPin = 9;
int echoPin = 8;
int bouton = 4;

long duration;
int distance;
unsigned long previousMillis = 0;
const long interval = 30000;

void setup() 
{
  servo.attach(7);
  servo.write(0);
  delay(2000);

  pinMode(LedRouge, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (digitalRead(bouton) == HIGH){
    servo.write(60);
    delay(3000);
    servo.write(0);
    previousMillis = millis();
  } 

  if (millis() - previousMillis >= interval) {
    servo.write(60);
    delay(3000);
    servo.write(0);
    previousMillis = millis();
  }

  if (distance < 12) {
    digitalWrite(LedRouge, HIGH);
  } else {
    digitalWrite(LedRouge, LOW);
  }
}
