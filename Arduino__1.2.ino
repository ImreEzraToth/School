int buttonPin = 2;
const int stepPin = 3;
const int dirPin = 4;
int RelayPin = 5;
int buttonNew;
int LEDState = 0;
int buttonOld = 1;
int LEDPin = 7;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dirPin, HIGH);
  pinMode(stepPin, HIGH);
  pinMode(LEDPin, OUTPUT);
  pinMode(RelayPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  buttonNew = digitalRead(buttonPin);
  if (buttonOld == 0 && buttonNew == 1) {
    if (LEDState == 0) {
      digitalWrite(RelayPin, HIGH);
      Serial.println("button Pressed");
      delay(60000);
      for (int i = 0; i <= 1800; i++) {
        //delayMicroseconds(1000);
        //digitalWrite(stepPin,LOW);
        //delayMicroseconds(1000);
        digitalWrite(LEDPin, HIGH);
        Serial.print(0 + i );
        Serial.println("lampje aan");
        delay(500);
      }
      digitalWrite(7, LOW);
      Serial.print("lampje uit voor 100 seconde");
      delay(100000);
      for (int i = 0; i <= 1800; i++) {
        //delayMicroseconds(1000);
        //digitalWrite(stepPin,LOW);
        //delayMicroseconds(1000);
        //delay(500);}
        Serial.print(0 + i);
        Serial.println("lampje aan");
        digitalWrite(LEDPin, HIGH);
        delay(130000);
        digitalWrite(LEDPin, LOW);
        delay(1000000000);

        LEDState = 1;
      }
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
