#include <Stepper.h>

char incomingByte;                    // a variable to read incoming serial data into
String incomingCommand;               // Varible to store the command
    
int stepperGearing;
int stepperSpeed;
long int totalSteps;                 // This varible is the complete steps around the rotational platter.
int circleSubdivide;                 // Takes in a number, which is then 360/X ; equals the angle to increment
long int location = 0;               // Stores absolute location of motor. 

int laserPin0 = 11 ;                  // Hook the laser up to pin 13
bool laserOn0 = 0 ;                   // varible to query state of laser

int laserPin1 = 12 ;                  // Hook the laser up to pin 13
bool laserOn1 = 0 ;                   // varible to query state of laser

int ledPin = 13;

// 15360 steps per full external plate revolution using my motor, indicates 320:1 gearing. 
// Your gearing will be different.

void setup() {
  Serial.begin(9600);
  pinMode(laserPin0, OUTPUT);
  pinMode(laserPin1, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(laserPin0, LOW);
  digitalWrite(laserPin1, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  
    if (Serial.available() > 0) {
      incomingByte = Serial.read();
      incomingCommand.concat(String(incomingByte));
    }
    if ( incomingCommand.endsWith(".") || incomingCommand.endsWith("?") ){
      executeCode(incomingCommand);
      incomingCommand.remove(0);
    }
    if ( incomingCommand.length() > 11 ){
      Serial.println("Length of command exceeded.");
      incomingCommand.remove(0);
    }
    
}

void executeCode(String code) {
  long int value ;
  int spaceIndex = code.indexOf(' '); // Figure out where the space is in the command, else -1
  String command;
  
  if (spaceIndex == -1){
    value = -1;
    if(code.endsWith(".")){ 
      command = code.substring(0,code.indexOf('.'));
    }
    else{
      command = code.substring(0,code.indexOf("?"));
    }
  } 
  else {
    value = code.substring((spaceIndex+1), code.length()).toInt();
    command = code.substring(0,spaceIndex);
  }
    
    if(command == "M1"){                // Creates Stepper
      if(code.endsWith(".")) {
        stepperGearing = value;
        Stepper motor(stepperGearing,7,8,9,10);
        Serial.println("OK");}
      if(code.endsWith("?")) {
        Serial.println(stepperGearing);}
    }
    
    if(command == "M2"){                // Sets speed of stepper
      if(code.endsWith(".")) {
        stepperSpeed = value;
        Serial.println("OK");}
      if(code.endsWith("?")) {
        Serial.println(stepperSpeed);}
    }
        
    if(command == "M3"){               // Sets how many total steps to rotate platter one revolution
      if(code.endsWith(".")) {
        totalSteps = value;
        Serial.println("OK");}
      if(code.endsWith("?")) {
        Serial.println(totalSteps);}
    }
        
    if(command == "M4"){               // Sets how many parts to divide the circle. If you want 100 parts, set this as 100
      if(code.endsWith(".")) {
        circleSubdivide = value;
        Serial.println("OK");}
      if(code.endsWith("?")) {
        Serial.print(circleSubdivide);
        Serial.print("  ");
        Serial.print(360.0/circleSubdivide, 6);
        Serial.print("  ");
        Serial.println((int)(totalSteps / circleSubdivide));}
    }
    
    
    if(command == "G0"){             // Absolute forward, increments stepper by value
      Stepper motor(stepperGearing,7,8,9,10);
      motor.setSpeed(stepperSpeed);
      digitalWrite(ledPin, HIGH);
      motor.step(value);
      digitalWrite(ledPin, LOW);
      location = location + value;
      Serial.println("OK");
    }
    
    if(command == "G1"){              // Absolute backward, decrements stepper by value
      Stepper motor(stepperGearing,7,8,9,10);
      motor.setSpeed(stepperSpeed);
      digitalWrite(ledPin, HIGH);
      motor.step(-1*value);
      digitalWrite(ledPin, LOW);
      location = location - value;
      Serial.println("OK");
    }
      
    if(command == "G2"){             // Increments steps to do part of circle
      int stepCalculate = value * (totalSteps/circleSubdivide); 
      Stepper motor(stepperGearing,7,8,9,10);
      motor.setSpeed(stepperSpeed);
      digitalWrite(ledPin, HIGH);
      motor.step(stepCalculate);
      digitalWrite(ledPin, LOW);
      location = location + stepCalculate;
      Serial.println("OK");
    }
    
    if(command == "G3"){            // Decrements steps to do part of circle
      int stepCalculate = value * (totalSteps/circleSubdivide); 
      Stepper motor(stepperGearing,7,8,9,10);
      motor.setSpeed(stepperSpeed);
      digitalWrite(ledPin, HIGH);
      motor.step(-1*stepCalculate);
      digitalWrite(ledPin, LOW);
      location = location - stepCalculate;
      Serial.println("OK");
    }
      
      
    if(command == "L0"){                      //laser toggle
      if(code.endsWith(".")) {
        if(value == 0){
          digitalWrite(laserPin0, LOW);
          laserOn0 = 0;
          Serial.println("OK");
        } else{
          digitalWrite(laserPin0, HIGH);
          laserOn0 = 1;
          Serial.println("OK");
        }
      }
      if(code.endsWith("?")) {
        if(laserOn0 == 1){Serial.println("ON");}
        else{Serial.println("OFF");}
      }
    }
    
    if(command == "L1"){                      //laser toggle
      if(code.endsWith(".")) {
        if(value == 0){
          digitalWrite(laserPin1, LOW);
          laserOn1 = 0;
          Serial.println("OK");
        } else{
          digitalWrite(laserPin1, HIGH);
          laserOn1 = 1;
          Serial.println("OK");
        }
      }
      if(code.endsWith("?")) {
        if(laserOn1 == 1){Serial.println("ON");}
        else{Serial.println("OFF");}
      }
    }

    
    
    if(command == "RESET"){
      Stepper motor(stepperGearing,7,8,9,10);   // Resets position to 0
      motor.setSpeed(stepperSpeed);
      
      while(location >= totalSteps){ 
        location = location - totalSteps;}
      while(location < totalSteps){ 
        location = location + totalSteps;} 
      
      if(location < totalSteps*.5){
        digitalWrite(ledPin, HIGH);
        motor.step(-1*location);
        digitalWrite(ledPin, LOW);}
        else{
          digitalWrite(ledPin, HIGH);
          motor.step(totalSteps-location);
        digitalWrite(ledPin, LOW);}
      location = 0;
      Serial.println("OK");
    }
      
      
    if(command == "POS"){          // prints position
      Serial.println(location);
    }
    
    if(command == "ZERO"){
      location = 0 ;
      Serial.println("OK");
    }
    
    
    return ;
}
