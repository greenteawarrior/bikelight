 // set constants
const int buttonPin = 8;
const int ledPin0 = 9;
const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;
const int ledPin4 = 13;

//set variables (will change)
boolean oldState;
boolean newState;
boolean ledOn = 0;
boolean ledConfig = 0;
int modecounter = 0;
int mode = 0;
int sensorVoltage;
long oldTime;
long newTime;
long passedTime;

//begin
void setup() {
  //allows serial monitor print
  Serial.begin(9600);
  
  //initialize the LED pins
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  
  //initialize the button pin
  pinMode(oldState, INPUT);
  pinMode(newState, INPUT);
  
  //initialize the sensor pin
  pinMode(A0, INPUT);
  
  //first time oldState is being read and first time oldTime is being recorded
  oldState = digitalRead(buttonPin);
  oldTime = millis();
}

//looping
void loop() {
  //taking new readings at the beginning of each loop
  newState = digitalRead(buttonPin);
  newTime = millis();
  passedTime = newTime - oldTime;
  
  //was the button pressed?!
  if (oldState == 0 && newState == 1){
    modecounter = modecounter + 1;
    mode = modecounter % 5;
  }
  
  if (passedTime >= 1000) 
  {
    //reset oldTime after 1 sec has passed
    oldTime = newTime;
    
    //act according to mode
    if (mode == 0){
    //All On
      Serial.println("All On");
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);             
    }
    
    else if (mode == 1){
    //Flashing
      Serial.println("Flashing");

      if (ledOn == 0){ // change to ledOn = 1 
        digitalWrite(ledPin0, HIGH);
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        ledOn = 1;        
      }
      else if (ledOn == 1){ // change to ledOn = 0 
        digitalWrite(ledPin0, LOW);
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        ledOn = 0;
      } 
    }

    else if (mode == 2){
    //Bouncing 
      Serial.println("Bouncing");
      
      if (ledConfig == 0){ // change to ledConfig = 1 
        digitalWrite(ledPin0, HIGH);
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, HIGH);
        ledConfig = 1;        
      }
      else if (ledConfig == 1){ // change to ledConfig = 0 
        digitalWrite(ledPin0, LOW);
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, LOW);
        ledConfig = 0;
      } 
    }

    else if (mode == 3){
    //All Off
      Serial.println("All off");
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);             
    }

    else if (mode == 4){
      sensorVoltage = analogRead(A0);
      Serial.println("Infrared time!");
      Serial.println("sensorVoltage:");
      Serial.println(sensorVoltage);
      Serial.println("");
        
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
  }
  // at the end of this loop() iteration,
  // oldState obtains the value of newState to maintain the 
  // definition that "oldState is the state of the button 
  // at the very end of the previous loop" 
  oldState = newState;
}

