#include "LED.h"

Led::Led(uint8_t pin) : //* Classe :: (:: = se referencia) a Metodo construtor
                        pino(pin),
                        estado(LOW),
                        apagarNoTempo(false),
                        apagarNoMomento(false),
                        estadoPiscar(false),
                        tempoEspera(0),
                        tempoAnteriorPiscar(0),
                        repeticoes(0)
{
    pino = pin; //* pino (Atributo/Variavel) recebe pin.
    estado = LOW;
    pinMode(pino, OUTPUT);
}

void Led::acender() //* Tipo da funçao -> Classe -> Função
{
    estado = HIGH;
    estadoPiscar = false;
    apagarNoTempo = false;
}

void Led::acender(uint32_t tempoLigado)
{
    estado = HIGH;
    apagarNoTempo = true;
    estadoPiscar = false;
    apagarNoMomento = millis() + tempoLigado;
}

void Led::apagar()
{
    estado = LOW;
    estadoPiscar = false;
    apagarNoTempo = false;
}

void Led::piscar() //* Pisca com freq de 1sec (50/50)
{
    estadoPiscar = true;
    apagarNoTempo = false;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    repeticoes = -1;
}

void Led::piscar(float freq) //* Pisca com freq
{
    estadoPiscar = true;
    apagarNoTempo = false;
    tempoEspera = (1000.0f / (2.0f * freq));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    repeticoes = -1;

    if (freq == 0)
        return;
}

void Led::piscar(float freq, uint16_t repeticoes) //* Pisca com freq e rep definida
{
    estadoPiscar = true;
    apagarNoTempo = false;
    tempoEspera = (1000.0f / (2.0f * freq));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;

    if (freq == 0)
        return;
}

void Led::alternar()
{
    estado = !estado;
    estadoPiscar = false;
    apagarNoTempo = false;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
    estadoPiscar = false;
    apagarNoTempo = false;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::funcaoApagarNoTempo() //* Atualiza a função apagar no update
{
    if (millis() >= apagarNoMomento)
    {
        estado = LOW;
        apagarNoTempo = false;
    }
}

void Led::funcaoPiscar() //* Atualiza a função piscar no update
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}

void Led::update() //* Usado no inicio do loop pois é ele que atualiza o pino e o estado
{
    if (apagarNoTempo)
        funcaoApagarNoTempo();

    if (estadoPiscar)
        funcaoPiscar();

    digitalWrite(pino, estado);
}