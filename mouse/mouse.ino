#include <Mouse.h>

// Pines del joystick
const int pinX = A0;
const int pinY = A1;
const int pinClic = 2;

// Pines de los botones
const int button1Pin = 5;
const int button2Pin = 3;

// Pines del RGB
const int redPin = 8;
const int greenPin = 9;
const int bluePin = 6;

void setup() {
  pinMode(pinClic, INPUT_PULLUP);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Mouse.begin();
}

void loop() {
  moverMouse();
  manejarClics();
  delay(10);
}

void moverMouse() {
  int xVal = analogRead(pinX) - 512;
  int yVal = analogRead(pinY) - 512;

  xVal = xVal / 10;
  yVal = yVal / 10;

  if (xVal != 0 || yVal != 0) {
    Mouse.move(xVal, yVal);
    digitalWrite(greenPin, HIGH);  // Indica movimiento del mouse
  } else {
    digitalWrite(greenPin, LOW);
  }
}

void manejarClics() {
  if (digitalRead(pinClic) == LOW) {
    if (!Mouse.isPressed(MOUSE_MIDDLE)) {
      Mouse.press(MOUSE_MIDDLE);
      mostrarColor(bluePin);  // Indica clic del joystick
    }
  } else {
    if (Mouse.isPressed(MOUSE_MIDDLE)) {
      Mouse.release(MOUSE_MIDDLE);
    }
  }

  if (digitalRead(button1Pin) == LOW) {
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
      mostrarColor(redPin);  // Indica clic del botón 1
    }
  } else {
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  if (digitalRead(button2Pin) == LOW) {
    if (!Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.press(MOUSE_RIGHT);
      mostrarColor(bluePin);  // Indica clic del botón 2
    }
  } else {
    if (Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.release(MOUSE_RIGHT);
    }
  }
}

void mostrarColor(int pin) {
  digitalWrite(pin, HIGH);
  delay(100);  // Mantiene el color por un tiempo breve
  digitalWrite(pin, LOW);
}
