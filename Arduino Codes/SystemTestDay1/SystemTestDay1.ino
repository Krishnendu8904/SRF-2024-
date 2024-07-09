#include <Servo.h>

Servo serA;
Servo serB;
int LED = 2;

void setup() {
  // put your setup code here, to run once:
  serA.attach(14, 500,  2500);
  serB.attach(13, 500, 2500);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pos;
  for(pos =0; pos <=90; pos++){
    serA.write(pos);
    serB.write(180-pos);
    Serial.println("setting");
    digitalWrite(2, LOW);
  }
  delay(3000);
  //current state 90 90
  for(pos =90; pos <=180; pos++){
    serA.write(pos);
    serB.write(180-pos);
    Serial.println("Upstroke");
    digitalWrite(2, LOW);
  }
  delay(5000);
  digitalWrite(2, HIGH);
  for(pos=0; pos<=180; pos++){
    serB.write(pos);
  }
  for(pos=180; pos>=90; pos--){
    serA.write(pos);
  }
  for(pos=180; pos>=90; pos--){
    serB.write(pos);
  }
  delay(5000);
  
}
