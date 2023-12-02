const int buttonPin = 2;
bool buttonPressed = false;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(buttonPin);
  if (val == HIGH) {
    if (!buttonPressed) {
      Serial.println("Button pressed");
      buttonPressed = true;
    }
  } else {
    if (buttonPressed) {
      Serial.println("Button released");
      buttonPressed = false;
    }
  }
}
