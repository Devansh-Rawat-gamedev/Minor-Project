#include "Renderer.h"
#include "Game.h"
#include "./GameObjects/Ball.h"
#include "./GameObjects/Platform.h"
#include "./GameObjects/Block.h"
#include <GL/freeglut.h>
#include <cmath>
#include <string>


void Renderer::initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    // Initialize stars
    stars.clear();
    for (int i = 0; i < NUM_STARS; ++i) {
        Star star;
        star.x = static_cast<float>(rand() % WINDOW_WIDTH);
        star.y = static_cast<float>(rand() % WINDOW_HEIGHT);
        star.size = static_cast<float>(rand() % 3 + 1);
        stars.push_back(star);
    }
}

void Renderer::render(const Game& game) {
    glClear(GL_COLOR_BUFFER_BIT);

    drawStars();

    if (!game.isGameOver()) {
        drawBall(game.getBall());
        drawPlatform(game.getPlatform());
        drawBlocks(game.getLevelManager().getBlocks());
        drawScore(game.getScore());
    }
    else {
        drawGameOver(game.getScore());
    }

    glutSwapBuffers();
}

void Renderer::drawStars() {
    glColor3f(1.0f, 1.0f, 1.0f);
    for (const auto& star : stars) {
        glBegin(GL_QUADS);
        glVertex2f(star.x - star.size, star.y - star.size);
        glVertex2f(star.x + star.size, star.y - star.size);
        glVertex2f(star.x + star.size, star.y + star.size);
        glVertex2f(star.x - star.size, star.y + star.size);
        glEnd();
    }
}

void Renderer::drawBall(const Ball& ball) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float radian = i * 3.14159f / 180.0f;
        glVertex2f(ball.getX() + cos(radian) * ball.getRadius(),
            ball.getY() + sin(radian) * ball.getRadius());
    }
    glEnd();
}

void Renderer::drawPlatform(const Platform& platform) {
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(platform.getX() - platform.getWidth() / 2, platform.getY() - platform.getHeight() / 2);
    glVertex2f(platform.getX() + platform.getWidth() / 2, platform.getY() - platform.getHeight() / 2);
    glVertex2f(platform.getX() + platform.getWidth() / 2, platform.getY() + platform.getHeight() / 2);
    glVertex2f(platform.getX() - platform.getWidth() / 2, platform.getY() + platform.getHeight() / 2);
    glEnd();
}

void Renderer::drawBlocks(const std::vector<Block>& blocks) {
    for (const auto& block : blocks) {
        
        if (block.isActive()) {
            glColor3f(1.0f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex2f(block.getX() - block.getWidth() / 2, block.getY() - block.getHeight() / 2);
            glVertex2f(block.getX() + block.getWidth() / 2, block.getY() - block.getHeight() / 2);
            glVertex2f(block.getX() + block.getWidth() / 2, block.getY() + block.getHeight() / 2);
            glVertex2f(block.getX() - block.getWidth() / 2, block.getY() + block.getHeight() / 2);
            glEnd();
        }
    }
}

void Renderer::drawScore(int score) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(10, 30);
    std::string scoreText = "Score: " + std::to_string(score);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void Renderer::drawGameOver(int score) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2);
    std::string message = "Game Over! Score: " + std::to_string(score);
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glRasterPos2f(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 + 40);
    std::string gameOverInstructions = "'R' - Reset, 'Q' - Quit";
    for (char c : gameOverInstructions) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}