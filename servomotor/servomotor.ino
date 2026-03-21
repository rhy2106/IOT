#include <Servo.h>

int pos = 0;

Servo servo;
void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);

  servo.attach(9,500,2500);
}

void loop(){

  int potenciometro = map(analogRead(A0),0,1023, 0, 180);
  int led = map(potenciometro,0,180,0,2);

  for(int i = 0; i < 3; i++){
    if(i == led) digitalWrite(11 + i, HIGH);
    else digitalWrite(11 + i, LOW);
  }

  if(pos > potenciometro)
    servo.write(pos--);
  if(pos < potenciometro)
    servo.write(pos++);

  delay(15);
}
