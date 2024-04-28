#include <Arduino.h>

// Declaración global de la variable retul
  int result; 
// Declaración de la función:
int myFunction(int, int);

void setup() {
  // código que solo se ejecuta una vez:
  // inicio puerto serie 
  Serial.begin(115200);
  result = myFunction(2, 3);
}

void loop() {
  // código que se ejecuta repetidamente:
  Serial.print("El resultado de la función myFunction(2, 3) es ");
  Serial.println(result);
  delay(2000);
}

// Definición de la función:
int myFunction(int x, int y) {
  return x + y;
}