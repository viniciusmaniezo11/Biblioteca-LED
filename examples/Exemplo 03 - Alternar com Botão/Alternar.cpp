#include <Arduino.h>
#include <LED.h>

/**
 * Este é um exemplo da função alternar() utilizando do botão boot.
 */

Led ledA(45);
const uint8_t pinBotaoBoot = 0;

void setup() 
{
  pinMode(pinBotaoBoot, INPUT_PULLUP);
}

void loop() 
{
  bool estadoAtualBoot = digitalRead(pinBotaoBoot);
  static bool estadoAnteriorBoot = HIGH;

  if(estadoAnteriorBoot && !estadoAtualBoot)
  {
    ledA.alternar(); // Alterna o estado do LED.
  }
  estadoAnteriorBoot = estadoAtualBoot;
  ledA.update(); // Este metódo deve sempre ser chamado no loop().
}
