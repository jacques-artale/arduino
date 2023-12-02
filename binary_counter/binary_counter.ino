// Define the LED_BUILTIN pin as the LED pin
const int buttonPin = 2;
int value = 0;

int ledStart = 9;
int ledEnd = 12;

void setup() {
  // Initialize the digital pin as an output.
  for (int i = ledStart; i <= ledEnd; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  int val = digitalRead(buttonPin);
  if (val == HIGH) {
    value++;
    if (value > 15) {
      value = 0;
    }
    delay(200);
  }

  displayValue();
}

void displayValue() {
  int val = value;
  for (int i = ledStart; i <= ledEnd; i++) {
    digitalWrite(i, val % 2);
    val /= 2;
  }
}
