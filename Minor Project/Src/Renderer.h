#pragma once

#include <vector>

class Game;
class Ball;
class Platform;
class Block;

struct Star {
    float x, y;
    float size;
};

class Renderer {
public:
    void initOpenGL();
    void render(const Game& game);

private:
    void drawStars();
    void drawBall(const Ball& ball);
    void drawPlatform(const Platform& platform);
    void drawBlocks(const std::vector<Block>& blocks);
    void drawScore(int score);
    void drawGameOver(int score);

    static constexpr int NUM_STARS = 100;
    std::vector<Star> stars;
};