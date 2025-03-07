#include "DigiMouse.h"
#include <math.h>

#define SPEED 5       // Intervalo de tempo entre atualizações (ms)
#define STEP 0.2      // Passo do ângulo (ajusta a suavidade do movimento)
#define RADIUS 0.6    // Raio máximo dentro do pixel
#define BUTTON_PIN 0  // Botão conectado ao pino P0

bool movimentoAtivo = false;  // Estado do movimento
bool lastButtonState = HIGH;  // Armazena o último estado do botão

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // Ativa o pull-up interno do Digispark
    DigiMouse.begin();  // Inicializa o mouse USB (importante!)
}

void loop() {
    bool buttonState = digitalRead(BUTTON_PIN); // Lê o estado do botão

    // Se o botão foi pressionado (transição de HIGH para LOW)
    if (buttonState == LOW && lastButtonState == HIGH) {
        movimentoAtivo = !movimentoAtivo;  // Alterna o estado
        delay(200);  // Pequeno atraso para evitar múltiplos acionamentos rápidos
    }

    lastButtonState = buttonState; // Atualiza o estado do botão

    if (movimentoAtivo) {
        static float angle = 0;
        float dx = RADIUS * cos(angle);
        float dy = RADIUS * sin(angle);

        DigiMouse.move(round(dx), round(dy), 0);
        DigiMouse.update();

        angle += STEP;
        if (angle >= 2 * M_PI) angle = 0;
    } else {
        DigiMouse.update();  // Precisa ser chamado no loop para evitar desconexões
    }

    delay(SPEED);
}
