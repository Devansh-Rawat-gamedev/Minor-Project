#pragma once

class InputManager {
public:
    void handleKeyPress(unsigned char key, int x, int y);
    void handleSpecialKeyPress(int key, int x, int y);
    void handleSpecialKeyRelease(int key, int x, int y);
    bool isMovingLeft() const { return moveLeft; }
    bool isMovingRight() const { return moveRight; }

private:
    bool moveLeft = false;
    bool moveRight = false;
};