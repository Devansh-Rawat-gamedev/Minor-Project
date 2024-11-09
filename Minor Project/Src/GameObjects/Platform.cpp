#include "Platform.h"
#include "../Game.h"
#include "../InputManager.h"

void Platform::update() {
    const InputManager& input = Game::getInstance().getInputManager();
    if (input.isMovingLeft() && x > width / 2) {
        x -= speed;
    }
    if (input.isMovingRight() && x < WINDOW_WIDTH - width / 2) {
        x += speed;
    }
}

void Platform::reset() {
    x = WINDOW_WIDTH / 2;
    y = WINDOW_HEIGHT - 30;
}