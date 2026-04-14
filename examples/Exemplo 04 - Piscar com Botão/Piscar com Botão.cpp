#include <Arduino.h>
#include <LED.h>

/**
 * Este é um exemplo da função piscar() e suas sobrecargas utilizando o botão boot.
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
    ledA.piscar(2, 26); // Led piscará em uma frequência de 2hz com 26 repetições somente ao clicar o botão.
  }
  estadoAnteriorBoot = estadoAtualBoot;
  ledA.update(); // Este metódo deve sempre ser chamado no loop().
}
