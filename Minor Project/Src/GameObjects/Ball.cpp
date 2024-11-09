#include "Ball.h"
#include "../Game.h"

void Ball::update() {
    x += dx;
    y += dy;
}

void Ball::reset() {
    x = WINDOW_WIDTH / 2;
    y = WINDOW_HEIGHT / 2;
    dx = 3.0f;
    dy = -3.0f;
}