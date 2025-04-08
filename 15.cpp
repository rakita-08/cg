#include <GL/glut.h>
#include <iostream>
class OpenGLApp {
private:
static float angle; // Rotation angle
public:
static void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
glLoadIdentity(); // Reset transformations
glTranslatef(0.0f, 0.0f, -5.0f); // Move cube back so it's visible
// Rotate cube around X, Y, Z axes
glRotatef(angle, 1.0f, 1.0f, 1.0f);
// Draw a colored cube
glBegin(GL_QUADS);
// Front face (red)

glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
// Back face (green)
glColor3f(0.0f, 1.0f, 0.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);
// Top face (blue)
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, 1.0f, -1.0f);
// Bottom face (yellow)
glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
// Right face (cyan)
glColor3f(0.0f, 1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, 1.0f);
// Left face (magenta)
glColor3f(1.0f, 0.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glEnd();
glutSwapBuffers(); // Swap buffers for smooth animation
}

static void idle() {
angle += 0.5f; // Increment angle for rotation
if (angle > 360.0f) angle -= 360.0f; // Keep angle in range
glutPostRedisplay(); // Request redraw
}
static void init() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0, 1.0, 1.0, 100.0); // Set perspective projection
glMatrixMode(GL_MODELVIEW);
}
void run(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Double buffering
glutInitWindowSize(500, 500);
glutCreateWindow("Rotating 3D Cube");
init();
glutDisplayFunc(display);
glutIdleFunc(idle); // Called when idle for animation
glutMainLoop();
}
};
float OpenGLApp::angle = 0.0f; // Initialize static member
int main(int argc, char** argv) {
OpenGLApp app;
app.run(argc, argv);
return 0;
}
