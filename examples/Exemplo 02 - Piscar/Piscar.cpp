#include <Arduino.h>
#include <LED.h>

/**
 * Este é um exemplo da função piscar() e suas sobrecargas.
 */

Led ledA(45);
bool jaFeito = false;

void setup() 
{
}

void loop() 
{
  if(!jaFeito)
  {
    ledA.piscar(2, 20); // LED irá piscar em uma frequência de 2Hz com o maximo de 20 repetições.
    jaFeito = true;
  }
  ledA.update(); // Este metódo deve sempre ser chamado no loop().
}
