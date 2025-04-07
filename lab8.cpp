#include <iostream>
#include <graphics.h>
using namespace std;

// Function to draw the car at a given position (x, y)
void drawCar(int x, int y) {
// Car body (main rectangle)
setcolor(LIGHTGREEN);
setfillstyle(SOLID_FILL, LIGHTGREEN);
rectangle(x, y, x + 150, y + 50); // Body: 150x50 rectangle
floodfill(x + 10, y + 10, LIGHTGREEN);
// Car cabin (smaller rectangle on top)
setcolor(LIGHTCYAN);
setfillstyle(SOLID_FILL,LIGHTCYAN);
rectangle(x + 40, y - 30, x + 110, y); // Cabin: 70x30 rectangle
floodfill(x + 50, y - 10, LIGHTCYAN);
// Wheels
setcolor(BLACK);
setfillstyle(SOLID_FILL, BLACK);
circle(x + 30, y + 50, 15); // Left wheel
floodfill(x + 30, y + 50, BLACK);
circle(x + 120, y + 50, 15); // Right wheel
floodfill(x + 120, y + 50, BLACK);
// Window details (lines on cabin)
setcolor(LIGHTMAGENTA);
line(x + 40, y - 30, x + 75, y - 30); // Top of cabin
line(x + 75, y - 30, x + 110, y - 30); // Top of cabin
line(x + 75, y - 30, x + 75, y); // Middle of cabin (window separator)
}
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm,NULL); // Initialize graphics mode
// Set background to white
setbkcolor(LIGHTGRAY);
cleardevice();
// Get screen dimensions
int maxX = getmaxx(); // Maximum X coordinate (right edge)
int maxY = getmaxy(); // Maximum Y coordinate (bottom edge)
// Starting position (bottom-left corner)
int x = 0;
int y = maxY - 60; // Position the car just above the bottom edge (accounting for car height)
// Translation loop: Move from left to right
for (x = 0; x <= maxX - 150; x += 5) { // Stop before the car goes off-screen (car width = 150)

cleardevice(); // Clear the screen for animation
setbkcolor(LIGHTGRAY); // Set background to white
drawCar(x, y); // Draw the car at the new position
delay(50); // Delay for smooth animation (50ms)
}
// Wait for user input before closing
cout << "Press any key to exit...";
cin.get();
closegraph();
return 0;
}