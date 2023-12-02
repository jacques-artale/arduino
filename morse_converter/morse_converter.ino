#include "Queue.h"

const int displayPin = 12;
const int buzzerPin = 11;
const int buttonPin = 2;

CharQueue queue;

void setup() {
  pinMode(displayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  // test sound
  tone(buzzerPin, 1000);
  delay(100);
  tone(buzzerPin, 600);
  delay(100);
  tone(buzzerPin, 200);
  delay(100);
  noTone(buzzerPin);
}

void loop() {
  int val = digitalRead(buttonPin);
  if (val == HIGH) {
    digitalWrite(displayPin, HIGH);
    tone(buzzerPin, 1000);
  } else {
    digitalWrite(displayPin, LOW);
    noTone(buzzerPin);
  }

  // read serial data
  if (Serial.available() > 0) {
    String data = Serial.readString();
    for (int i = 0; i < data.length(); i++) {
      queue.push(data[i]);
    }
  }
  if (!queue.isEmpty()) {
    display();
  }
}

// display characters in queue as morse code
void display() {
  while (!queue.isEmpty()) {
    char c = queue.pop();
    String morse = toMorse(c);
    for (int i = 0; i < morse.length(); i++) {
      if (morse[i] == '.') {
        triggerOutput(100);
        delay(100);
      } else if (morse[i] == '-') {
        triggerOutput(300);
        delay(100);
      } else {
        delay(300);
      }
    }
    delay(100);
  }
}

// trigger output (LED and buzzer) for a given duration
void triggerOutput(int duration) {
  digitalWrite(displayPin, HIGH);
  tone(buzzerPin, 1000);
  delay(duration);
  digitalWrite(displayPin, LOW);
  noTone(buzzerPin);
}

String toMorse(char c) {
  switch (c) {
    case 'a':
      return ".-";
    case 'b':
      return "-...";
    case 'c':
      return "-.-.";
    case 'd':
      return "-..";
    case 'e':
      return ".";
    case 'f':
      return "..-.";
    case 'g':
      return "--.";
    case 'h':
      return "....";
    case 'i':
      return "..";
    case 'j':
      return ".---";
    case 'k':
      return "-.-";
    case 'l':
      return ".-..";
    case 'm':
      return "--";
    case 'n':
      return "-.";
    case 'o':
      return "---";
    case 'p':
      return ".--.";
    case 'q':
      return "--.-";
    case 'r':
      return ".-.";
    case 's':
      return "...";
    case 't':
      return "-";
    case 'u':
      return "..-";
    case 'v':
      return "...-";
    case 'w':
      return ".--";
    case 'x':
      return "-..-";
    case 'y':
      return "-.--";
    case 'z':
      return "--..";
    default:
      return "";
  }
}
