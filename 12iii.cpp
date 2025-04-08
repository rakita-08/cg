 #include <GL/glut.h> 
// Global variables for rotation 
float angleX = 0.0f; 
float angleY = 0.0f; 
void init() { 
 // Set background color to white 
 glClearColor(1.0, 1.0, 1.0, 1.0); 
  
 // Enable depth testing 
 glEnable(GL_DEPTH_TEST); 
  
 // Enable back-face culling 
 glEnable(GL_CULL_FACE); 
 glCullFace(GL_BACK); // Cull back-facing polygons 
  
 // Set front face winding order (default is counter-clockwise) 
 glFrontFace(GL_CCW); 
} 
void drawCube() { 
 glBegin(GL_QUADS); 
 
 // Front face (red) 
 glColor3f(1.0, 0.0, 0.0);  glVertex3f(-1.0, -1.0, 1.0);  glVertex3f( 1.0, -1.0, 1.0);  glVertex3f( 1.0, 1.0, 1.0);  glVertex3f(-1.0, 1.0, 1.0);   
 // Back face (green)  glColor3f(0.0, 1.0, 0.0);  glVertex3f(-1.0, -1.0, -1.0);  glVertex3f(-1.0, 1.0, -1.0);  glVertex3f( 1.0, 1.0, -1.0);  glVertex3f( 1.0, -1.0, -1.0);   
 // Left face (blue) 
 glColor3f(0.0, 0.0, 1.0);  glVertex3f(-1.0, -1.0, -1.0);  glVertex3f(-1.0, -1.0, 1.0);  glVertex3f(-1.0, 1.0, 1.0);  glVertex3f(-1.0, 1.0, -1.0);   
 // Right face (yellow)  glColor3f(1.0, 1.0, 0.0);  glVertex3f( 1.0, -1.0, -1.0);  glVertex3f( 1.0, 1.0, -1.0);  glVertex3f( 1.0, 1.0, 1.0);  glVertex3f( 1.0, -1.0, 1.0);   
 // Top face (cyan) 
 glColor3f(0.0, 1.0, 1.0);  glVertex3f(-1.0, 1.0, -1.0);  glVertex3f(-1.0, 1.0, 1.0);  glVertex3f( 1.0, 1.0, 1.0);  glVertex3f( 1.0, 1.0, -1.0);   
 // Bottom face (magenta)  glColor3f(1.0, 0.0, 1.0);  glVertex3f(-1.0, -1.0, -1.0);  glVertex3f( 1.0, -1.0, -1.0);  glVertex3f( 1.0, -1.0, 1.0);  glVertex3f(-1.0, -1.0, 1.0);   
 glEnd(); 
} 
void display() {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
 glLoadIdentity(); 
 // Set camera position 
 gluLookAt(3.0, 3.0, 3.0, // eye position 
 0.0, 0.0, 0.0, // look at point 
 0.0, 1.0, 0.0); // up vector 
  
 // Apply rotations 
 glRotatef(angleX, 1.0, 0.0, 0.0); 
 glRotatef(angleY, 0.0, 1.0, 0.0); 
  
 drawCube(); 
  
 glutSwapBuffers(); 
} 
void reshape(int width, int height) { 
 glViewport(0, 0, width, height); 
 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity(); 
 gluPerspective(45.0, (float)width/height, 0.1, 100.0);  glMatrixMode(GL_MODELVIEW); 
} 
void idle() { 
 // Rotate the cube continuously 
 angleX += 0.5f; 
 angleY += 0.7f; 
 glutPostRedisplay(); 
} 
void keyboard(unsigned char key, int x, int y) { 
 switch (key) { 
 case 'b': // Toggle back-face culling 
 if (glIsEnabled(GL_CULL_FACE)) 
 glDisable(GL_CULL_FACE); 
 else 
 glEnable(GL_CULL_FACE); 
 break; 
 case 27: // Escape key to exit 
 exit(0); 
 break; 
 } 
 glutPostRedisplay(); 
}
int main(int argc, char** argv) { 
 glutInit(&argc, argv); 
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
 glutInitWindowSize(800, 600); 
 glutCreateWindow("Back-Face Detection Demo");  
 init();  
 glutDisplayFunc(display); 
 glutReshapeFunc(reshape); 
 glutIdleFunc(idle); 
 glutKeyboardFunc(keyboard);  
 glutMainLoop(); 
 return 0; 
} 

