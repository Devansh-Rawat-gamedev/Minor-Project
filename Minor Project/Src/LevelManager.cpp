#include "LevelManager.h"
#include "Game.h"
#include <cmath>

void LevelManager::reset() {
    blocks.clear();
    float blockWidth = WINDOW_WIDTH / NUM_BLOCKS_X;
    float blockHeight = 20.0f;
    for (int i = 0; i < NUM_BLOCKS_Y; ++i) {
        for (int j = 0; j < NUM_BLOCKS_X; ++j) {
            Block block;
            block.setX(j * blockWidth + blockWidth / 2);
            block.setY(i * blockHeight + blockHeight / 2 + 50);
            blocks.push_back(block);
        }
    }
}

void LevelManager::checkCollisions(Ball& ball, Platform& platform) {
    // Ball wall collision
    if (ball.getX() - ball.getRadius() <= 0 || ball.getX() + ball.getRadius() >= WINDOW_WIDTH) {
        ball.setDX(-ball.getDX());
    }
    if (ball.getY() - ball.getRadius() <= 0) {
        ball.setDY(-ball.getDY());
    }

    // Ball platform collision
    if (ball.getY() + ball.getRadius() >= platform.getY() - platform.getHeight() / 2 &&
        ball.getY() - ball.getRadius() <= platform.getY() + platform.getHeight() / 2 &&
        ball.getX() >= platform.getX() - platform.getWidth() / 2 &&
        ball.getX() <= platform.getX() + platform.getWidth() / 2) {
        float relativeIntersectX = (ball.getX() - platform.getX()) / (platform.getWidth() / 2);
        ball.setDX(relativeIntersectX * 5.0f);
        ball.setDY(-std::abs(ball.getDY()));
    }

    // Ball brick collision
    for (auto& block : blocks) {
        if (block.isActive() &&
            ball.getX() + ball.getRadius() >= block.getX() - block.getWidth() / 2 &&
            ball.getX() - ball.getRadius() <= block.getX() + block.getWidth() / 2 &&
            ball.getY() + ball.getRadius() >= block.getY() - block.getHeight() / 2 &&
            ball.getY() - ball.getRadius() <= block.getY() + block.getHeight() / 2) {
            block.setActive(false);
            ball.setDY(-ball.getDY());
            Game::getInstance().incrementScore();
            break;
        }
    }

    // Check for game over
    if (ball.getY() + ball.getRadius() >= WINDOW_HEIGHT) {
        Game::getInstance().setGameOver(true);
    }
}