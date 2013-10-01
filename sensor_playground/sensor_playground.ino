//set constants
const int ledPin0 = 9;
const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;
const int ledPin4 = 13;

//set variables
int sensorVoltage;

//begin
void setup() {
  //allows serial monitor print
  Serial.begin(9600);
  
  //initialize the LED pin
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  
  //initialize sensor pin
  pinMode(A0, INPUT);
}

//looping
void loop() {
  sensorVoltage = analogRead(A0);
  Serial.println(sensorVoltage);
    
  if (sensorVoltage <= 560 && sensorVoltage >= 400) {
    Serial.println(sensorVoltage);
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  
  else if (sensorVoltage <= 399 && sensorVoltage >= 280) {
    Serial.println(sensorVoltage);
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
   
  else if (sensorVoltage <= 279 && sensorVoltage >= 220) {
    Serial.println(sensorVoltage);
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  
  else if (sensorVoltage <= 219 && sensorVoltage >= 160) {
    Serial.println(sensorVoltage);
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
  }
  
  else if (sensorVoltage <= 159 && sensorVoltage >= 140) {
    Serial.println(sensorVoltage);
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
  }

  else {
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }
  
}

