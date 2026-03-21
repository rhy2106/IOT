int button = 0;

void setup(){
	pinMode(2,INPUT_PULLUP);

	pinMode(13,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(11,OUTPUT);

	pinMode(10,OUTPUT);
	pinMode(9,OUTPUT);
}

void loop(){
	button = digitalRead(2);
	if( button == LOW ){
		digitalWrite(13, LOW);
		digitalWrite(12, HIGH);
		delay(1000);
		digitalWrite(12,LOW);
		digitalWrite(11,HIGH);
		delay(1000);
		
		digitalWrite(9,LOW); // vermelho
		digitalWrite(10,HIGH); // verde
		delay(2000);
		for(int i = 0; i < 4; i++){
			digitalWrite(9,HIGH);
			delay(250);
			digitalWrite(9,LOW);
			delay(250);
		}
		digitalWrite(9,HIGH);
		digitalWrite(10,LOW);
      	digitalWrite(11,LOW);

	} else {
		digitalWrite(9,HIGH);
		digitalWrite(13,HIGH);
	}
	delay(10);
	
}

