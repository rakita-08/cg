#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
// Function to apply 2D translation
void translate(int &x, int &y, int tx, int ty) {
x += tx;
y += ty;
}
// Function to apply 2D scaling (with centroid correction)
void scale(float &x, float &y, float sx, float sy, float cx, float cy) {
x = cx + (x - cx) * sx;
y = cy + (y - cy) * sy;
}
// Function to apply 2D rotation around centroid

void rotate(float &x, float &y, float angle, float cx, float cy) {
float rad = angle * M_PI / 180.0; // Convert angle to radians
float x_new = cx + (x - cx) * cos(rad) - (y - cy) * sin(rad);
float y_new = cy + (x - cx) * sin(rad) + (y - cy) * cos(rad);
x = x_new;
y = y_new;
}
// Function to draw a triangle
void drawShape(int x1, int y1, int x2, int y2, int x3, int y3) {
line(x1, y1, x2, y2);
line(x2, y2, x3, y3);
line(x3, y3, x1, y1);
}
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);
int x1 = 100, y1 = 100;
int x2 = 200, y2 = 100;
int x3 = 150, y3 = 200;
setbkcolor(MAGENTA);
cleardevice();
setcolor(YELLOW);
drawShape(x1, y1, x2, y2, x3, y3); // Draw original shape
int choice;
char proceed;
do {
// Compute centroid for rotation and scaling
float cx = (x1 + x2 + x3) / 3.0;
float cy = (y1 + y2 + y3) / 3.0;
cout << "\nSelect a transformation:\n";
cout << "1. Translation\n";
cout << "2. Scaling\n";

cout << "3. Rotation\n";
cout << "Enter your choice (1/2/3): ";
cin >> choice;
float x1f = x1, y1f = y1;
float x2f = x2, y2f = y2;
float x3f = x3, y3f = y3;
switch (choice) {
case 1: {
// Translation
int tx, ty;
cout << "Enter translation values (tx, ty): ";
cin >> tx >> ty;
translate(x1, y1, tx, ty);
translate(x2, y2, tx, ty);
translate(x3, y3, tx, ty);
break;
}
case 2: {
// Scaling (about centroid)
float sx, sy;
cout << "Enter scaling factors (sx, sy): ";
cin >> sx >> sy;
scale(x1f, y1f, sx, sy, cx, cy);
scale(x2f, y2f, sx, sy, cx, cy);
scale(x3f, y3f, sx, sy, cx, cy);
break;
}
case 3: {
// Rotation (around centroid)
float angle;
cout << "Enter the rotation angle: ";
cin >> angle;
rotate(x1f, y1f, angle, cx, cy);
rotate(x2f, y2f, angle, cx, cy);
rotate(x3f, y3f, angle, cx, cy);
break;
}
default:

cout << "Invalid choice!\n";
continue;
}
// Convert floating point values back to integer
x1 = round(x1f); y1 = round(y1f);
x2 = round(x2f); y2 = round(y2f);
x3 = round(x3f); y3 = round(y3f);
cleardevice(); // Clear previous drawings
setcolor(WHITE);
drawShape(x1, y1, x2, y2, x3, y3); // Draw updated shape
// Ask if the user wants to continue
cout << "Do you want to apply another transformation? (y/n): ";
cin >> proceed;
} while (proceed == 'y' || proceed == 'Y');
cout << "Press any key to exit...";
getch(); // Wait for key press
closegraph();
return 0;
}