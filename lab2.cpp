#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>
using namespace std;
// DDA Line Drawing Algorithm
void ddaLine(int x1, int y1, int x2, int y2) {
int dx = x2 - x1;
int dy = y2 - y1;
int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
float xIncrement = dx / (float)steps;
float yIncrement = dy / (float)steps;
float x = x1;
float y = y1;
for (int i = 0; i <= steps; i++) {
putpixel(round(x), round(y), RED); // Plotting the pixel
x += xIncrement;
y += yIncrement;
}
}

// Bresenham's Line Drawing Algorithm
void bresenhamLine(int x1, int y1, int x2, int y2) {
int dx = x2 - x1;
int dy = y2 - y1;
int dx2 = 2 * dx;
int dy2 = 2 * dy;
int x = x1, y = y1;
int p = dy2 - dx;
if (dy < 0) {
dy = -dy;
dx2 = -dx2;
}
if (dx < 0) {
dx = -dx;
dy2 = -dy2;
}
if (dy <= dx) { // Shallow slope
while (x != x2) {
putpixel(x, y, BLUE);
x += (x2 > x1 ? 1 : -1);
if (p < 0) {
p += dy2;
} else {
p += dy2 - dx2;
y += (y2 > y1 ? 1 : -1);
}
}
} else { // Steep slope
while (y != y2) {
putpixel(x, y, BLUE);
y += (y2 > y1 ? 1 : -1);
if (p <= 0) {
p += dx2;
} else {
p += dx2 - dy2;
x += (x2 > x1 ? 1 : -1);
}
}
}
}
int main() {
int gd = DETECT, gm;

initgraph(&gd, &gm, NULL);
int x1, y1, x2, y2;
int choice;
// Set background color to something visible (e.g., green)
setbkcolor(WHITE); // Green background
cleardevice(); // Apply the background color
// Get user input for the coordinates
cout << "Enter the coordinates of the starting point (x1, y1): ";
cin >> x1 >> y1;
cout << "Enter the coordinates of the ending point (x2, y2): ";
cin >> x2 >> y2;
// Get the user's choice of algorithm
cout << "\nChoose the Line Drawing Algorithm:\n";
cout << "1. DDA Algorithm\n";
cout << "2. Bresenham Algorithm\n";
cout << "Enter your choice (1 or 2): ";
cin >> choice;
// Draw the line based on the user's choice
switch(choice) {
case 1:
ddaLine(x1, y1, x2, y2);
break;
case 2:
bresenhamLine(x1, y1, x2, y2);
break;
default:
cout << "Invalid choice! Exiting...\n";
break;
}
getch(); // Wait for user input
closegraph(); // Close the graphics window
return 0;
}