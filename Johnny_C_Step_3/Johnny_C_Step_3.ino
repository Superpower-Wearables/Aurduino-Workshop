int sensorPin = A0;    // select the input pin for the potentiometer
int RED = 13;
int GREEN =12; 
// select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  Serial.println(sensorValue);
  sensorValue = analogRead(sensorPin);
  if(sensorValue >1000)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    delay(100);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    delay(100);
  }
  else if(sensorValue > 550)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  }
  
  else if(sensorValue >100)
  {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
  else
  { 
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
  }
  
  delay(2);
}
