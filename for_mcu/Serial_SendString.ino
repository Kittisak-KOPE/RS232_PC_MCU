void setup() {
  Serial.begin(9600);
}

void loop() {
  char TextToSend[] = "Hello! This is massage from Arduino Uno";
  Serial.println(TextToSend);
  delay(1000);
}
