#include <Servo.h>

int pos_servo = 0;
Servo servo;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT); // temperatura
  pinMode(A1, INPUT); // luminosidade solar
  pinMode(A2, INPUT); // umidade

  pinMode(10, OUTPUT); // modulo Rele
  pinMode(9, OUTPUT); // buzzer
  pinMode(8, OUTPUT); // Motor CC

  servo.attach(7,500,2500);

  pinMode(10,OUTPUT);
}

void loop(){
    int temperatura = map(analogRead(A0), 20, 358, 0, 100);
    int luz = map(analogRead(A1),1017,344,0,100);
    int umidade = map(analogRead(A2),0,1023,0,100);

    Serial.print("temperatura: ");
    Serial.print(temperatura);
    Serial.print('\n');

    Serial.print("luz: ");
    Serial.print(luz);
    Serial.print('\n');

    Serial.print("umidade: ");
    Serial.print(umidade);
    Serial.print('\n');

    if(temperatura > 28 && luz > 70){
        if(pos_servo < 90) servo.write(pos_servo++);
    } else if(pos_servo > 0) servo.write(pos_servo--);

    if(umidade < 70) digitalWrite(8,HIGH);
    else digitalWrite(8,LOW);
    if(temperatura > 45) tone(9, 440);
    else noTone(9);
    delay(30);

  //digitalWrite(1,HIGH);
}
