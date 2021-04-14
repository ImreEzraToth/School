int LEDState = 0;
int LEDPin = 7;
int buttonPin = 2;
int buttonNew;
int buttonOld = 1;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}
  
void loop() {
  buttonNew = digitalRead(buttonPin);
  if (buttonOld == 0 && buttonNew == 1) {
    if (LEDState == 0) {
      delay(99000);
      for (int i = 0; i <100; i++) {
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
        delay(500);
      }
      delay(950000);
       for (int i = 0; i <100; i++) {
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
        delay(500);}
        delay(50000);
        Delay(1000000000);
                 
      
      LEDState = 1;

    }
    else {
      digitalWrite(LEDPin, LOW);
      Serial.println("IM NOT ON! :?");
      LEDState = 0;
    }
  }
  buttonOld = buttonNew;
  delay(dt);
}
