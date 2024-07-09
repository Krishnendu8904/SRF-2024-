#include <Servo.h>

Servo leftservo;
Servo rightservo;
float l, r;

int lpos = 45;
int rpos = 135;  
int inc = 1;

void setup() {
  Serial.begin(115200);  //begin serial monitor with a baud rate
  leftservo.attach(12);   
  rightservo.attach(15);
  leftservo.write(lpos);
  rightservo.write(rpos);
}

void loop() {
  userInput();
  while (1) {
    if(lpos == l && rpos ==r){
      break;
    }
    if (lpos == l && rpos == r) {
      break;
    }
    if (lpos < l) {
      lpos = lpos + inc;
    } else if (lpos > l) {
      lpos = lpos - inc;
    }

    if (rpos < r) {
      rpos = rpos + inc;
    } else if (rpos > r) {
      rpos = rpos - inc;
    }
    leftservo.write(lpos);
    rightservo.write(rpos);
    delay(100);
  }
}

//Ask user for angle inpput
void userInput() {
  Serial.end();
  Serial.begin(115200);
  Serial.println("Enter angle 'left' and 'right' in degrees");
  Serial.print("angle 'left' >   ");
  while (true) {
    if (Serial.available()) {
      l = Serial.parseFloat();
      Serial.print(l);
      l=l+45;
      break;
    }
  }
  Serial.end();
  Serial.begin(115200);
  Serial.println();
  Serial.print("angle 'right' >  ");
  while (true) {
    if (Serial.available() > 0) {
      r = Serial.parseFloat();
      Serial.print(r);
      r=r+135;
      break;
    }
  }
  Serial.println();
}
