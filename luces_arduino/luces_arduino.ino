int switchState = 0;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);

}

void prenderApagar(int pin){
    digitalWrite(pin,HIGH);
    delay(300);
    digitalWrite(pin,LOW);
    delay(250);
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW){
    prenderApagar(3);
    prenderApagar(4);
    prenderApagar(5);

  }
  
  else{
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    delay(590);
  }

}
