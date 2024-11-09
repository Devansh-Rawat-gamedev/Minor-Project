#include "Game.h"
#include <GL/freeglut.h>



Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::init() {
    renderer.initOpenGL();
    reset();
}

void Game::update() {
    if (!gameOver) {
        ball.update();
        platform.update();
        levelManager.checkCollisions(ball, platform);
    }
    glutPostRedisplay();
    glutTimerFunc(16, [](int value) { Game::getInstance().update(); }, 0);
}

void Game::render() {
    renderer.render(*this);
}

void Game::reset() {
    ball.reset();
    platform.reset();
    levelManager.reset();
    gameOver = false;
    score = 0;
}