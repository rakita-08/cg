#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
// Line coordinates (start and end points)
float linePoints[2][2] = {
{100, 300}, // Start point (x1, y1)
{200, 200} // End point (x2, y2)
};
// Transformed line coordinates
float transformedLine[2][2];
// Function to draw the line
void drawLine(float points[2][2], int color) {
setcolor(color);
line(points[0][0], points[0][1], points[1][0], points[1][1]);
}
// Function to perform translation
void translate(float tx, float ty) {
for (int i = 0; i < 2; i++) {
transformedLine[i][0] = linePoints[i][0] + tx; // x' = x + tx
transformedLine[i][1] = linePoints[i][1] + ty; // y' = y + ty
}

}
// Function to perform rotation around the origin
void rotate(float angle) {
float rad = angle * (M_PI / 180.0); // Convert degrees to radians
for (int i = 0; i < 2; i++) {
float x = linePoints[i][0];
float y = linePoints[i][1];
transformedLine[i][0] = x * cos(rad) - y * sin(rad); // x' = x * cos(?) - y * sin(?)
transformedLine[i][1] = x * sin(rad) + y * cos(rad); // y' = x * sin(?) + y * cos(?)
}
}
// Function to perform scaling relative to the origin
void scale(float sx, float sy) {
for (int i = 0; i < 2; i++) {
transformedLine[i][0] = linePoints[i][0] * sx; // x' = x * sx
transformedLine[i][1] = linePoints[i][1] * sy; // y' = y * sy
}
}
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm,NULL); // Initialize graphics mode
// Set background to white
setbkcolor(LIGHTGREEN);
cleardevice();
// Draw original line (red)
drawLine(linePoints, MAGENTA);
// Translation
float tx = 50, ty = 50;
cout << "Applying Translation (tx = " << tx << ", ty = " << ty << ")\n";
translate(tx, ty);
drawLine(transformedLine, BLACK); // Draw translated line (green)
// Copy transformed line back to original for next transformation
for (int i = 0; i < 2; i++) {
linePoints[i][0] = transformedLine[i][0];
linePoints[i][1] = transformedLine[i][1];
}
// Rotation
float angle = 45; // Rotate by 45 degrees

cout << "Applying Rotation (angle = " << angle << " degrees)\n";
rotate(angle);
drawLine(transformedLine, LIGHTGRAY); // Draw rotated line (blue)
// Copy transformed line back to original for next transformation
for (int i = 0; i < 2; i++) {
linePoints[i][0] = transformedLine[i][0];
linePoints[i][1] = transformedLine[i][1];
}
// Scaling
float sx = 1.5, sy = 1.5; // Scale by 1.5 in both directions
cout << "Applying Scaling (sx = " << sx << ", sy = " << sy << ")\n";
scale(sx, sy);
drawLine(transformedLine, MAGENTA); // Draw scaled line (magenta)
// Wait for user input before closing
cout << "Press any key to exit...";
getch();
closegraph();
return 0;
}