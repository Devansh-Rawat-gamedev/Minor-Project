#pragma once

#include "GameObjects/Ball.h"
#include "GameObjects/Platform.h"
#include "LevelManager.h"
#include "InputManager.h"
#include "Renderer.h"

class Game {
public:
    static Game& getInstance();
    void init();
    void update();
    void render();
    void reset();
    InputManager& getInputManager() { return inputManager; }
    const Ball& getBall() const { return ball; }
    const Platform& getPlatform() const { return platform; }
    const LevelManager& getLevelManager() const { return levelManager; }
    bool isGameOver() const { return gameOver; }
    void setGameOver(bool value) { gameOver = value; }
    int getScore() const { return score; }
    void incrementScore() { score++; }

private:
    Game() = default;
    ~Game() = default;
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    Ball ball;
    Platform platform;
    LevelManager levelManager;
    InputManager inputManager;
    Renderer renderer;
    bool gameOver = false;
    int score = 0;
};


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600