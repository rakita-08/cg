#include <iostream>
#include <graphics.h>
using namespace std;
// Rectangle coordinates (before shear)
float rect[4][2] = {
{100, 300}, // Bottom-left
{200, 300}, // Bottom-right
{200, 200}, // Top-right
{100, 200} // Top-left
};
// Sheared rectangle coordinates
float shearedRect[4][2];
// Shear factor
float shearX = 0.5; // Shear along X based on Y
// Function to apply shear transformation
void applyShear() {
for (int i = 0; i < 4; i++) {
// Shear along X: x' = x + shearX * (y - baseY), y' = y
// Using bottom Y (300) as the base to keep the bottom edge fixed
shearedRect[i][0] = rect[i][0] + shearX * (rect[i][1] - rect[0][1]);
shearedRect[i][1] = rect[i][1];
}
}
// Function to draw a rectangle
void drawRectangle(float points[4][2], int color) {
setcolor(color);
line(points[0][0], points[0][1], points[1][0], points[1][1]); // Bottom
line(points[1][0], points[1][1], points[2][0], points[2][1]); // Right

line(points[2][0], points[2][1], points[3][0], points[3][1]); // Top
line(points[3][0], points[3][1], points[0][0], points[0][1]); // Left
}
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm,NULL); // Initialize graphics mode
// Set background to green
setbkcolor(LIGHTGRAY);
cleardevice(); // Clear the screen to apply the background color
// Draw original rectangle (red)
drawRectangle(rect, MAGENTA);
// Apply shear transformation
applyShear();
// Draw sheared rectangle (green)
drawRectangle(shearedRect, CYAN); // Using LIGHTGREEN for visibility on green
// Wait for user input before closing
cout << "Press any key to exit...";
getch(); // Wait for a key press
closegraph(); // Close graphics window
return 0;
}