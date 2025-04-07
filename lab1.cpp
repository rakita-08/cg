#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
using namespace std;
void drawBasicGraphics() {
// Initialize graphics mode
int gd = DETECT, gm;
initgraph(&gd,&gm,NULL);
// Set background color to something visible (e.g., green)
setbkcolor(WHITE); // Green background
cleardevice(); // Apply the background color
// Set the color of drawing shapes
setcolor(RED); // Red color for shapes
// Draw a rectangle
rectangle(100, 100, 300, 200);
// Draw a circle
circle(400, 150, 50);
// Draw an ellipse
ellipse(600, 150, 0, 360, 100, 50);
// Draw a line
line(100, 300, 500, 300);
// Draw a filled circle (using flood fill)
setfillstyle(SOLID_FILL, BLUE);
floodfill(400, 150, RED); // Fill the circle with blue color
// Display text on the screen
// Wait for the user to press any key before closing the window
getch();
// Close the graphics mode
closegraph();
}
int main() {
drawBasicGraphics();

return 0;
}