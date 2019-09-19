//USING SIMPLE ANALOGUE SENSOR TO FADE AN LED

const int ledPin5 = 5;
const int ledPin4= 4;  
const int ledPin3 = 3;     //PWM pin 3 to LED
const int sensorPin = A0; //Sensor connects to A0 analog pin


int value; //Variable to track sensor input


void setup(){
  pinMode(ledPin5, OUTPUT);  //Set pin 3 as output
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin3, OUTPUT);
       //Begin serial communication
}


void loop(){
  value = analogRead(sensorPin);       //Read and save analog value from sensor
  Serial.println(value);               //Print value
  value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin5, value);          //Use value to control LED
  value = map(value, 0, 1023, 0, 255);
  analogWrite(ledPin4, value);
  value = map(value, 0, 550, 0, 255);
  analogWrite(ledPin3, value);
  delay(100);                          //Small delay
  
}
