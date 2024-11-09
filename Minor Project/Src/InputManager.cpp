#include "InputManager.h"
#include "Game.h"
#include <GL/freeglut.h>

void InputManager::handleKeyPress(unsigned char key, int x, int y) {
    if (key == 'r' || key == 'R') {
        Game::getInstance().reset();
    }
    else if (key == 'q' || key == 'Q' || key == 27) {
        Game::getInstance().setGameOver(true);
    }
}

void InputManager::handleSpecialKeyPress(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        moveLeft = true;
    }
    else if (key == GLUT_KEY_RIGHT) {
        moveRight = true;
    }
}

void InputManager::handleSpecialKeyRelease(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        moveLeft = false;
    }
    else if (key == GLUT_KEY_RIGHT) {
        moveRight = false;
    }
}