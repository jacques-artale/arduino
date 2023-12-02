// Define the LED_BUILTIN pin as the LED pin
const int ledPin = 13;

void setup() {
  // Initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);

}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000); // Wait for 100 milliseconds
  digitalWrite(ledPin, LOW); // Turn the LED off
  delay(1000); // Wait for another 100 milliseconds
}
