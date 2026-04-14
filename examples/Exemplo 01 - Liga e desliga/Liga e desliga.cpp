#include <Arduino.h>
#include <LED.h>

/**
 * Este é um exemplo das funções acender() e apagar() da biblioteca.
 */

Led ledA(45);

void setup() 
{
}

void loop() 
{
  ledA.update(); // Este metódo deve sempre ser chamado no loop().

  ledA.acender(); // Liga o LED.
  delay(1000);
  ledA.apagar(); // Desliga o LED.
  delay(1000);
}
