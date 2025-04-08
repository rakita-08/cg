#include <GL/glut.h>
#include <iostream>
class OpenGLApp {
public:
static void display() {
glClear(GL_COLOR_BUFFER_BIT);
// Draw a point
glPointSize(10.0f); // Set point size
glColor3f(1.0f, 0.0f, 0.0f); // Red
glBegin(GL_POINTS);
glVertex2f(0.0f, 0.5f); // Center-top
glEnd();
// Draw a line
glLineWidth(3.0f); // Set line width
glColor3f(0.0f, 1.0f, 0.0f); // Green
glBegin(GL_LINES);

glVertex2f(-0.5f, 0.0f); // Left-middle
glVertex2f(0.5f, 0.0f); // Right-middle
glEnd();
// Draw a polygon (triangle)
glColor3f(0.0f, 0.0f, 1.0f); // Blue
glBegin(GL_TRIANGLES);
glVertex2f(0.0f, -0.5f); // Bottom-center
glVertex2f(-0.5f, -0.8f); // Bottom-left
glVertex2f(0.5f, -0.8f); // Bottom-right
glEnd();
glFlush(); // Render the scene
}
static void init() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 2D orthographic projection
glMatrixMode(GL_MODELVIEW);
}
void run(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutCreateWindow("Point, Line, Polygon");
init();
glutDisplayFunc(display);
glutMainLoop();
}
};
int main(int argc, char** argv) {
OpenGLApp app;
app.run(argc, argv);
return 0;
}
