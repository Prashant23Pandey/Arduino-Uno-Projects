const int soundSensor = 2;
const int Led1 = 3;
const int Led2 = 5;
const int Led3 = 6;
void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
}
void loop() {
  int soundValue = digitalRead(soundSensor);
  Serial.print("Sound Level:  ");
  Serial.println(soundValue);
  digitalWrite(redLed, soundValue);
  digitalWrite(greenLed, soundValue);
  digitalWrite(blueLed, soundValue);
  delay(1);
}