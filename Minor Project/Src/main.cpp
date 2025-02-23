#include <GL/glut.h>
#include <iostream>

// Fractal parameters
float centerX = -0.5f, centerY = 0.0f; // Center of the fractal view
float zoom = 1.0f;                     // Zoom level
const int maxIterations = 500;         // Iteration depth
float cReal = -0.7f, cImag = 0.27015f; // Change for different patterns

// Window dimensions
const int windowWidth = 800, windowHeight = 800;

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int depth) {
    if (depth == 0) {
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    }
    else {
        float midX1 = (x1 + x2) / 2.0f;
        float midY1 = (y1 + y2) / 2.0f;

        float midX2 = (x2 + x3) / 2.0f;
        float midY2 = (y2 + y3) / 2.0f;

        float midX3 = (x1 + x3) / 2.0f;
        float midY3 = (y1 + y3) / 2.0f;

        drawTriangle(x1, y1, midX1, midY1, midX3, midY3, depth - 1);
        drawTriangle(midX1, midY1, x2, y2, midX2, midY2, depth - 1);
        drawTriangle(midX3, midY3, midX2, midY2, x3, y3, depth - 1);
    }
}
void drawKochCurve(float x1, float y1, float x2, float y2, int depth) {
    if (depth == 0) {
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    else {
        // Divide the line into 3 segments
        float dx = (x2 - x1) / 3.0f;
        float dy = (y2 - y1) / 3.0f;

        // Points for the Koch curve
        float xA = x1 + dx;
        float yA = y1 + dy;

        float xB = x1 + 2.0f * dx;
        float yB = y1 + 2.0f * dy;

        // Point forming the "peak" of the triangle
        float xPeak = (xA + xB) / 2.0f - (yB - yA) * sqrt(3.0f) / 2.0f;
        float yPeak = (yA + yB) / 2.0f + (xB - xA) * sqrt(3.0f) / 2.0f;

        // Recursively draw each segment
        drawKochCurve(x1, y1, xA, yA, depth - 1);
        drawKochCurve(xA, yA, xPeak, yPeak, depth - 1);
        drawKochCurve(xPeak, yPeak, xB, yB, depth - 1);
        drawKochCurve(xB, yB, x2, y2, depth - 1);
    }


}
void drawCantorSet(float x1, float y1, float x2, float y2, int depth) {
    if (depth == 0)
        return;

    float midX = (x1 + x2) / 2.0f;

    // Draw the line segment
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    // Recurse for both sides
    drawCantorSet(x1, y1 + 0.1f, midX, y2 + 0.1f, depth - 1);
    drawCantorSet(midX, y2 + 0.1f, x2, y1 + 0.1f, depth - 1);
}

void drawCarpet(float x, float y, float size, int depth) {
    if (depth == 0)
        return;

    float newSize = size / 3.0f;

    // Draw 9 smaller squares and leave the center empty
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0)
                continue; // Skip the center

            drawCarpet(x + i * newSize, y + j * newSize, newSize, depth - 1);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);

    // Recursion depth
    int depth = 5;
    drawCarpet(-1.0f, -1.0f, 2.0f, depth);

    glEnd();
    glFlush();
}








void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': centerY += 0.1f / zoom; break; // Pan up
    case 's': centerY -= 0.1f / zoom; break; // Pan down
    case 'a': centerX -= 0.1f / zoom; break; // Pan left
    case 'd': centerX += 0.1f / zoom; break; // Pan right
    case '+': zoom *= 1.1f; break;           // Zoom in
    case '-': zoom /= 1.1f; break;           // Zoom out
    case 27: exit(0);                        // ESC to exit
    default: break;
    }
    glutPostRedisplay(); // Redraw the fractal
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Mandelbrot Fractal Generator");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();

    return 0;
}
