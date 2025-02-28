#include "DigiMouse.h"
#include <math.h>

#define SPEED 5   // Intervalo de tempo entre cada atualização (ms)
#define STEP 0.2   // Passo do ângulo (ajusta a suavidade do movimento)
#define RADIUS 0.6 // Raio máximo dentro do pixel (ajustado para evitar escape)

void setup() {
    DigiMouse.begin(); // Inicializa a biblioteca DigiMouse
}

void loop() {
    static float angle = 0; // Ângulo do movimento circular acumulado

    // Calcula deslocamento mantendo o raio abaixo de 1 pixel
    float dx = RADIUS * cos(angle);
    float dy = RADIUS * sin(angle);

    // Move apenas quando houver mudança de posição perceptível
    DigiMouse.move(round(dx), round(dy), 0);
    DigiMouse.update(); // Atualiza o estado do mouse

    angle += STEP; // Avança o ângulo para o próximo ponto do círculo
    if (angle >= 2 * M_PI) angle = 0; // Reinicia o ângulo após um ciclo completo

    delay(SPEED); // Ajuste na suavidade do movimento
}
