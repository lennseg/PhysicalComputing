int gin = 5;            //assign 1st Solenoid to pin 5
int ledOne = 4;         //assign 1st LED to pin 4
int campari = 9;        //assign 2nd Solenoid to pin 9
int ledTwo = 8;         //assign 2nd LED to pin 8
int sweetVermouth = 12; //assign 3rd Solenoid to pin 12
int ledThree = 11;      //assign 3rd LED to pin 11
int strobe=100;         //this controls how fast the LEDs will blink in line
int pushButton = 13;     //push button to start dispenser
int switchState = 0;


void setup() {
  Serial.begin(9600);
  pinMode(gin, OUTPUT);               //define 1 Solenoid as an output
  pinMode(ledOne, OUTPUT);            //define 1 LED as an ouput
  pinMode(campari, OUTPUT);           //define 2 Solenoid as an output
  pinMode(ledTwo, OUTPUT);            //define 2 LED as an ouput
  pinMode(sweetVermouth, OUTPUT);     //define 3 Solenoid as an output
  pinMode(ledThree, OUTPUT);          //define 3 LED as an ouput
  pinMode(pushButton, INPUT);         //declare pushbutton as an input
}

void loop() {
    //this stops when the button is pressed
  
  digitalWrite (ledOne, HIGH);    //turns ON LED 1 
  delay(strobe);                  //controls how fast the LEDs flash
  digitalWrite (ledOne, LOW);     //turns OFF LED 1
  delay(strobe);
  digitalWrite (ledTwo, HIGH);    //turns ON LED 2
  delay(strobe);
  digitalWrite (ledTwo, LOW);     //turns OFF LED 2
  delay(strobe);
  digitalWrite (ledThree, HIGH);  //turns ON LED 3
  delay(strobe);
  digitalWrite (ledThree, LOW);   //turns OFF LED 3
  delay(strobe);
  
  switchState = digitalRead(pushButton);
  if (switchState ==  HIGH) {
  //when button is pressed an LED will show which solenoid is running
    
    //NEGRONI ON
    digitalWrite(gin, HIGH);            //OPENS solenoid 1
    digitalWrite(ledOne, HIGH);         //LED 1 is ON
    delay(5000);                        //5 second delay
    digitalWrite(campari, HIGH);        //OPENS solenoid 2
    digitalWrite(ledTwo, HIGH);         //LED 2 is OFF
    delay(5000);                        //5 second delay
    digitalWrite(sweetVermouth, HIGH);  //OEPNS solenoid 3
    digitalWrite(ledThree, HIGH);       //LED 3 is OFF
    delay(5000);                        //5 second delay

  } else {

    //NEGRONI OFF
    digitalWrite(gin, LOW);           //solenoid 1 is closed
    digitalWrite(ledOne, LOW);        //LED 1 is OFF
    digitalWrite(campari, LOW);       //solenoid 2 is closed
    digitalWrite(ledTwo, LOW);        //LED 2 is OFF
    digitalWrite(sweetVermouth, LOW); //solenoid 3 is closed
    digitalWrite(ledThree, LOW);      //LED 3 is OFF
  }
}

