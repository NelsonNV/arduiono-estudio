#include <Keyboard.h>

// Define los pines para los botones
const int button1Pin = 8; // Botón 1 en pin 8
const int button2Pin = 2; // Botón 2 en pin 2

// Define el pin para el LED rojo
const int redLEDPin = 3; // Pin para el LED rojo

void setup() {
  // Inicializa la librería Keyboard
  Keyboard.begin();
  
  // Configura los pines de los botones como entradas
  pinMode(button1Pin, INPUT_PULLUP); // Botón 1
  pinMode(button2Pin, INPUT_PULLUP); // Botón 2

  // Configura el pin del LED rojo como salida
  pinMode(redLEDPin, OUTPUT);
  
  // Inicialmente, el LED rojo está apagado
  digitalWrite(redLEDPin, LOW);
}

void loop() {
  // Lee el estado de los botones
  if (digitalRead(button1Pin) == LOW) { // Botón 1 presionado
    openNotepad();
    delay(500); // Espera un tiempo para evitar múltiples activaciones
  }

  if (digitalRead(button2Pin) == LOW) { // Botón 2 presionado
    openCalculator();
    delay(500); // Espera un tiempo para evitar múltiples activaciones
  }
}

void openNotepad() {
  // Indica que se está ejecutando (enciende el LED rojo)
  digitalWrite(redLEDPin, HIGH); // LED rojo encendido
  
  // Abre Notepad y escribe "Hello World"
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("notepad");
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(1000);
  Keyboard.print("Hello World");

  // Apaga el LED rojo después de ejecutar
  digitalWrite(redLEDPin, LOW); // LED rojo apagado
}

void openCalculator() {
  // Indica que se está ejecutando (enciende el LED rojo)
  digitalWrite(redLEDPin, HIGH); // LED rojo encendido
  
  // Abre la Calculadora
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("calc");
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);

  // Apaga el LED rojo después de ejecutar
  digitalWrite(redLEDPin, LOW); // LED rojo apagado
}
