void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
}

void loop() {
  char RxedByte = 0;
  if(Serial.available()){
    
    RxedByte = Serial.read();
    Serial.print(RxedByte);
  }
}
