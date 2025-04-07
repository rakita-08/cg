#include <iostream>
#include <graphics.h>
using namespace std;
// Function to draw a circle using Bresenham's Algorithm
void drawCircleBresenham(int xc, int yc, int r) {
int x = 0, y = r;
int d = 3 - 2 * r;
while (x <= y) {
putpixel(xc + x, yc + y, WHITE);
putpixel(xc - x, yc + y, WHITE);
putpixel(xc + x, yc - y, WHITE);
putpixel(xc - x, yc - y, WHITE);
putpixel(xc + y, yc + x, WHITE);
putpixel(xc - y, yc + x, WHITE);
putpixel(xc + y, yc - x, WHITE);
putpixel(xc - y, yc - x, WHITE);
if (d < 0) {
d += 4 * x + 6;
} else {
d += 4 * (x - y) + 10;
y--;
}
x++;
}
}
// Function to draw a circle using Mid-Point Algorithm

void drawCircleMidPoint(int xc, int yc, int r) {
int x = 0, y = r;
int p = 1 - r;
while (x <= y) {
putpixel(xc + x, yc + y, WHITE);
putpixel(xc - x, yc + y, WHITE);
putpixel(xc + x, yc - y, WHITE);
putpixel(xc - x, yc - y, WHITE);
putpixel(xc + y, yc + x, WHITE);
putpixel(xc - y, yc + x, WHITE);
putpixel(xc + y, yc - x, WHITE);
putpixel(xc - y, yc - x, WHITE);
if (p < 0) {
p += 2 * x + 3;
} else {
p += 2 * (x - y) + 5;
y--;
}
x++;
}
}
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm,NULL);
// Set background color to something visible (e.g., green)
setbkcolor(RED); // Green background
cleardevice(); // Apply the background color
int xc, yc, r, choice;
cout << "Enter the center (xc, yc) of the circle: ";
cin >> xc >> yc;
cout << "Enter the radius of the circle: ";
cin >> r;
cout << "Choose the algorithm: \n1. Bresenham's Algorithm\n2. Mid-Point Algorithm\nEnter your choice: "<<endl;
cin >> choice;
setcolor(WHITE);
if (choice == 1)
drawCircleBresenham(xc, yc, r);
else if (choice == 2)
drawCircleMidPoint(xc, yc, r);
else
cout << "Invalid choice!";

cout << "Press any key to exit...";
getch();
closegraph();
return 0;
}