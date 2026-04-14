Biblioteca LED:

# Biblioteca LED

O projeto é uma biblioteca simples não bloqueante de LED com Arduino e ESP32

A classe `LED` tem as seguintes funcionalidades

- Ligar o LED continuamente.
- Ligar o LED por tempo determinado.
- Desligar o LED.
- Alternar o estado do LED.
- Piscar continuamente.
- Determinar a frequência e repetições das piscadas.

O funcionamento da biblioteca é não bloqueante utilizando do `millis()`, devido a isso o `update()` deve ser chamado repetidamente dentro do `loop()`.

# Estrutura da biblioteca

LED/
├─ library.json
├─ README.md
├─ LICENSE
├─ src/
│   ├─ LED.h
│   └─ LED.cpp
└─ examples/