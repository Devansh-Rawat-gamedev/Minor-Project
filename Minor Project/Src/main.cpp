#include "Game.h"
#include <GL/freeglut.h>
#include <iostream>


void display();
void keyboardhandeler(unsigned char key, int x, int y);
void Specialhandeler(int key, int x, int y);
void SpecialUphandeler(int key, int x, int y);

void update(int vlaue);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Wreck IT");

    Game& game = Game::getInstance();
    game.init();

    glutDisplayFunc(display);

    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(keyboardhandeler);
    glutSpecialFunc(Specialhandeler);
    glutSpecialUpFunc(SpecialUphandeler);




    

    glutMainLoop();
    return 0;
}

void display() {
    Game::getInstance().render();
}


void keyboardhandeler(unsigned char key, int x, int y) {
     Game::getInstance().getInputManager().handleKeyPress(key, x, y); 
}

void Specialhandeler(int key, int x, int y) {
    Game::getInstance().getInputManager().handleSpecialKeyPress(key, x, y);
}

void SpecialUphandeler(int key, int x, int y) {
    Game::getInstance().getInputManager().handleSpecialKeyRelease(key, x, y);
}

void update(int value) {
    Game::getInstance().update(); 
}