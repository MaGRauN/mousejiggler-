#include "DigiMouse.h"
#include <math.h>

#define SPEED 5       // Time interval between updates (ms)
#define STEP 0.2      // Step of the angle (adjusts the smoothness of the movement)
#define RADIUS 0.6    // Maximum radius within the pixel
#define BUTTON_PIN 0  // Button connected to pin P0

bool movimentoAtivo = false;  // Movement state
bool lastButtonState = HIGH;  // Stores the last button state

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // Enables the internal pull-up of the Digispark
    DigiMouse.begin();  // Initializes the USB mouse (important!)
}

void loop() {
    bool buttonState = digitalRead(BUTTON_PIN); // Reads the button state

    // If the button is pressed (transition from HIGH to LOW)
    if (buttonState == LOW && lastButtonState == HIGH) {
        movimentoAtivo = !movimentoAtivo;  // Toggles the state
        delay(200);  // Small delay to prevent multiple fast triggers
    }

    lastButtonState = buttonState; // Updates the button state

    if (movimentoAtivo) {
        static float angle = 0; // Accumulated angle of the circular movement
        
        // Calculates displacement while keeping the radius under 1 pixel
        float dx = RADIUS * cos(angle);
        float dy = RADIUS * sin(angle);

        // Moves only when there is a perceptible position change
        DigiMouse.move(round(dx), round(dy), 0);
        DigiMouse.update(); // Updates the mouse state

        angle += STEP; // Advances the angle to the next point on the circle
        if (angle >= 2 * M_PI) angle = 0; // Resets the angle after a full cycle
    } else {
        DigiMouse.update();  // Needs to be called in the loop to avoid disconnections
    }

    delay(SPEED); // Adjusts the smoothness of the movement
}
