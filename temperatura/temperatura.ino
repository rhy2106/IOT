void setup(){
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}
void loop(){
  int luz = analogRead(A1);
  luz = map(luz, 1017,344,0,1);
  int tmp = analogRead(A0);
  tmp = map(tmp, 0, 1023, 1, 5);
  if(luz > 0){
    for(int i = 9; i <= 9+tmp; i++)
      digitalWrite(i,HIGH);
    for(int i = 9+tmp; i <= 13; i++)
      digitalWrite(i,LOW);
  } else{
    for(int i = 9; i <= 13; i++){
      digitalWrite(i,LOW);
    }
  }

}
