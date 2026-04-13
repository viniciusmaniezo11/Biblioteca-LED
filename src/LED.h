#ifndef LED_h //* If not defined: se o objeto for definido ele funciona, se não ele pula para o endif direto
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 *
 * Permite ligar, desligar, ligar por um tempo,
 * piscar continuamente e piscar por uma quantidade definida.
 *
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
class Led
{
private:
    uint8_t pino;
    bool estado;

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoApagarNoTempo();
    bool apagarNoTempo;
    uint32_t apagarNoMomento;

    /**
     * @brief Processa a lógica de piscada do LED.
     */
    void funcaoPiscar();
    bool estadoPiscar;
    uint32_t tempoEspera;
    uint32_t tempoAnteriorPiscar;
    uint16_t repeticoes;

public:
    /**
     * @brief Constrói um objeto LED.
     * @param pin pino ao qual o LED foi conectado.
     */
    Led(uint8_t pin);

    /**
     * @brief Liga o LED continuamente.
     */
    void acender();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado Tempo, em milissegundos, que o LED ficará ligado.
     */
    void acender(uint32_t tempoLigado);

    /**
     * @brief Desliga o LED e cancela modos automáticos.
     */
    void apagar();

    /**
     * @brief Inicia a piscagem do LED com uma frequência padrão de 1Hz.
     */
    void piscar();

    /**
     * @brief Inicia a piscagem do LED com uma frequência determinada.
     * @param freq Determina em quantos Hz o LED piscará.
     */
    void piscar(float freq);

    /**
     * @brief Inicia a piscagem do LED com frequência e repetições determinadas.
     * @param freq Determina em quantos Hz o LED piscará.
     * @param repeticoes Determina quantas vezes o LED irá piscar.
     */
    void piscar(float freq, uint16_t repeticoes);

    /**
     * @brief Alterna o estado do LED.
     */
    void alternar();

    /**
     * @brief Seta o estado do atributo estado de maneira segura.
     * @param estado Altera o estado entre HIGH ou LOW.
     */
    void setEstado(bool estado);

    /**
     * @brief Pega o número do pino.
     */
    uint8_t getPino();

    /**
     * @brief Atualiza a lógica interna da classe e escreve no pino.
     *
     * @note Deve ser chamado repetidamente dentro da função loop().
     */
    void update();
};

#endif //* End if: ele fecha o if como se fosse as {}