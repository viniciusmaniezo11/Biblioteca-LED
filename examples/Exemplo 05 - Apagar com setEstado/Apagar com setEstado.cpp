#include <Arduino.h>
#include <LED.h>

/**
 * Este é um exemplo da função piscar() e suas sobrecargas utilizando o botão boot.
 */

Led ledA(45);
bool jaAcendeu = true;

void setup()
{
}

void loop()
{
  if (jaAcendeu)
  {
    ledA.acender();
    jaAcendeu = false;
  }
  ledA.update();
  delay(5000);

  ledA.setEstado(false);
}
