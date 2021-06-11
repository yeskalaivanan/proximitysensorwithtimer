

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A1;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

const int OutputPin1 =  7;      // Positive Output
const int OutputPin2 =  8;      // Negative Output
const int ledPin =  13;      // the number of the LED pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  pinMode(OutputPin1, OUTPUT);  
  pinMode(OutputPin2, OUTPUT);

  digitalWrite(OutputPin1, HIGH);
  digitalWrite(OutputPin2, HIGH);
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
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

  if (sensorValue > 600)
  {
    sensorValue = 0;
    //digitalWrite(ledPin, HIGH);
    digitalWrite(OutputPin1, LOW);    
    delay(100);
    digitalWrite(OutputPin1, HIGH);
    delay(6000);
    digitalWrite(OutputPin2, LOW);
    delay(100);
    digitalWrite(OutputPin2, HIGH);
    digitalWrite(ledPin, LOW); 
    //delay(6000);   
  }
  

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(10);
}
