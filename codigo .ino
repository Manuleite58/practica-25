// C++ code
//

#include <Servo.h>

Servo miServo;
//pin potencienmetro
int pot = A0;
//pin servo
int servoPin = 8;
//posicion potenciometro
int potPos = 0;
//posicion servo
int servoPos;


void setup() {
  miServo.attach(servoPin);
  Serial.begin(9600);
  //mensaje para escribir un valor
  Serial.println("Escribe un valor entre 0 y 180 para controlar el servo:");
  delay(1000);
}
//comprobamos si hay orden no monitor serie
void loop() {
  if (Serial.available()) {
    int tmp = Serial.parseInt();
    if (tmp >= 0 && tmp <= 180) {
      servoPos = tmp;
      miServo.write(servoPos);
      Serial.print("Posicion del servo: ");
      Serial.println(servoPos);
      delay(1500);
    }
  }
  else {
    potPos = analogRead(pot);
    servoPos = map(potPos, 0, 1023, 0, 180);
    miServo.write(servoPos);
    Serial.print("Posicion del servo: ");
    Serial.println(servoPos);
    delay(100);
  }
}
