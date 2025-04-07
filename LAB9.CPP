#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
// Define cube vertices (8 vertices in 3D space)
float cube[8][3] = {
{50, 50, 50}, // Vertex 0: bottom-front-left (shifted from origin)
{100, 50, 50}, // Vertex 1: bottom-front-right
{100, 100, 50}, // Vertex 2: top-front-right

{50, 100, 50}, // Vertex 3: top-front-left
{50, 50, 100}, // Vertex 4: bottom-back-left
{100, 50, 100}, // Vertex 5: bottom-back-right
{100, 100, 100},// Vertex 6: top-back-right
{50, 100, 100} // Vertex 7: top-back-left
};
// Transformed cube vertices
float transformedCube[8][3];
// 2D projected points for drawing
int projected[8][2];
// Function to project 3D points to 2D (simple perspective projection)
void project() {
float focalLength = 300; // Increased focal length for better perspective
for (int i = 0; i < 8; i++) {
float x = transformedCube[i][0];
float y = transformedCube[i][1];
float z = transformedCube[i][2];
// Simple perspective projection: (x, y) = (f * x / (f + z), f * y / (f + z))
projected[i][0] = 300 + (focalLength * (x - 75)) / (focalLength + z); // Center at x=300, adjust for cube center
projected[i][1] = 300 - (focalLength * (y - 75)) / (focalLength + z); // Center at y=300, adjust for cube center
}
}
// Function to draw the cube
void drawCube(int color) {
setcolor(color);
// Front face (0-1-2-3)
line(projected[0][0], projected[0][1], projected[1][0], projected[1][1]);
line(projected[1][0], projected[1][1], projected[2][0], projected[2][1]);
line(projected[2][0], projected[2][1], projected[3][0], projected[3][1]);
line(projected[3][0], projected[3][1], projected[0][0], projected[0][1]);
// Back face (4-5-6-7)
line(projected[4][0], projected[4][1], projected[5][0], projected[5][1]);
line(projected[5][0], projected[5][1], projected[6][0], projected[6][1]);
line(projected[6][0], projected[6][1], projected[7][0], projected[7][1]);
line(projected[7][0], projected[7][1], projected[4][0], projected[4][1]);
// Connecting edges (0-4, 1-5, 2-6, 3-7)
line(projected[0][0], projected[0][1], projected[4][0], projected[4][1]);
line(projected[1][0], projected[1][1], projected[5][0], projected[5][1]);

line(projected[2][0], projected[2][1], projected[6][0], projected[6][1]);
line(projected[3][0], projected[3][1], projected[7][0], projected[7][1]);
}
// Function to copy cube to transformedCube
void copyCube() {
for (int i = 0; i < 8; i++) {
for (int j = 0; j < 3; j++) {
transformedCube[i][j] = cube[i][j];
}
}
}
// 9.1: Translation in X, Y, Z directions
void translate(float tx, float ty, float tz) {
for (int i = 0; i < 8; i++) {
transformedCube[i][0] += tx; // x' = x + tx
transformedCube[i][1] += ty; // y' = y + ty
transformedCube[i][2] += tz; // z' = z + tz
}
}
// 9.2: Rotation about Z-axis and Y-axis
void rotateZ(float angle) {
float rad = angle * (M_PI / 180.0); // Convert degrees to radians
for (int i = 0; i < 8; i++) {
float x = transformedCube[i][0] - 75; // Rotate around cube center (75, 75, 75)
float y = transformedCube[i][1] - 75;
transformedCube[i][0] = 75 + (x * cos(rad) - y * sin(rad)); // x' = x * cos(?) - y * sin(?)
transformedCube[i][1] = 75 + (x * sin(rad) + y * cos(rad)); // y' = x * sin(?) + y * cos(?)
// Z remains unchanged
}
}
void rotateY(float angle) {
float rad = angle * (M_PI / 180.0); // Convert degrees to radians
for (int i = 0; i < 8; i++) {
float x = transformedCube[i][0] - 75; // Rotate around cube center (75, 75, 75)
float z = transformedCube[i][2] - 75;
transformedCube[i][0] = 75 + (x * cos(rad) + z * sin(rad)); // x' = x * cos(?) + z * sin(?)
transformedCube[i][2] = 75 + (-x * sin(rad) + z * cos(rad)); // z' = -x * sin(?) + z * cos(?)
// Y remains unchanged
}
}
// 9.3: Scaling in X and Y directions

void scale(float sx, float sy, float sz) {
for (int i = 0; i < 8; i++) {
transformedCube[i][0] = (transformedCube[i][0] - 75) * sx + 75; // Scale around cube center
transformedCube[i][1] = (transformedCube[i][1] - 75) * sy + 75;
transformedCube[i][2] = (transformedCube[i][2] - 75) * sz + 75;
}
}
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm,NULL); // Initialize graphics mode
// Set background to white
setbkcolor(LIGHTMAGENTA);
cleardevice();
// Step 1: Draw original cube (red)
copyCube();
project();
drawCube(LIGHTRED);
cout << "Original cube drawn (lightred). Press any key to continue...\n";
cin.get();
cleardevice();
// 9.1: Translation (move by 50 in X, 50 in Y, 50 in Z)
translate(50, 50, 50);
project();
drawCube(LIGHTBLUE);
cout << "Translated cube drawn (lightblue). Press any key to continue...\n";
cin.get();
cleardevice();
// 9.2: Rotation (45° about Z-axis, then 60° about Y-axis)
rotateZ(45);
rotateY(60);
project();
drawCube(YELLOW);
cout << "Rotated cube drawn (yellow). Press any key to continue...\n";
cin.get();
cleardevice();
// 9.3: Scaling (2 in X, 3 in Y, 1 in Z)
scale(2, 3, 1);
project();
drawCube(BLUE);
cout << "Scaled cube drawn (Blue). Press any key to exit...\n";

cin.get();
closegraph();
return 0;
}