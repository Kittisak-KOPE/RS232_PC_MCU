void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
}

void loop() {

  char RxedByte = 0;
  if(Serial.available()){
    
    RxedByte = Serial.read();

    if(RxedByte == 'A' && RxedByte != 'B'){
      digitalWrite(13, HIGH);
    }

    if(RxedByte == 'B'){
      digitalWrite(13, LOW);
    }
  }
}
