// These variables store the flash pattern
// and the current state of the LED

int ledPin1 =  12;      // the number of the LED pin
int ledState1 = LOW;             // ledState used to set the LED
unsigned long previousMillis1 = 0;        // will store last time LED was updated
long OnTime1 = 250;           // milliseconds of on-time
long OffTime1 = 750;          // milliseconds of off-time

int ledPin2 =  13;      // the number of the LED pin
int ledState2 = LOW;             // ledState used to set the LED
unsigned long previousMillis2 = 0;        // will store last time LED was updated
long OnTime2 = 330;           // milliseconds of on-time
long OffTime2 = 400;          // milliseconds of off-time


int ledPin3 =  11;      // the number of the LED pin
int ledState3 = LOW;             // ledState used to set the LED
unsigned long previousMillis3 = 0;        // will store last time LED was updated
long OnTime3 = 330;           // milliseconds of on-time
long OffTime3 = 400;          // milliseconds of off-time

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 13; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() 
{
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);      
  pinMode(ledPin2, OUTPUT);

        Serial.begin(9600);
}

void loop()
{
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
 
  if((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
  {
    ledState1 = LOW;  // Turn it off
    previousMillis1 = currentMillis;  // Remember the time
    digitalWrite(ledPin1, ledState1);  // Update the actual LED
  }
  else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
  {
    ledState1 = HIGH;  // turn it on
    previousMillis1 = currentMillis;   // Remember the time
    digitalWrite(ledPin1, ledState1);    // Update the actual LED
  }
  
  if((ledState2 == HIGH) && (currentMillis - previousMillis2 >= OnTime2))
  {
    ledState2 = LOW;  // Turn it off
    previousMillis2 = currentMillis;  // Remember the time
    digitalWrite(ledPin2, ledState2);  // Update the actual LED
  }
  else if ((ledState2 == LOW) && (currentMillis - previousMillis2 >= OffTime2))
  {
    ledState2 = HIGH;  // turn it on
    previousMillis2 = currentMillis;   // Remember the time
    digitalWrite(ledPin2, ledState2);   // Update the actual LED
    

   if((ledState3 == HIGH) && (currentMillis - previousMillis3 >= OnTime3))
  {
    ledState3 = LOW;  // Turn it off
    previousMillis3 = currentMillis;  // Remember the time
    digitalWrite(ledPin3, ledState3);  // Update the actual LED
  }
  else if ((ledState3 == LOW) && (currentMillis - previousMillis3 >= OffTime3))
  {
    ledState3 = HIGH;  // turn it on
    previousMillis3 = currentMillis;   // Remember the time
    digitalWrite(ledPin3, ledState3);   // Update the actual LED
  }
    
    
    
    
    
    
    
    sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);




    
  }
}
