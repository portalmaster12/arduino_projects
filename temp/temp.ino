
const int sensorPin=A0;
const float baselineTemp=20.0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("\n Sensor Value: ");
  Serial.print(sensorVal);
  delay(1000);
  

}
