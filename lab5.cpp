#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;
const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;
int xmin, ymin, xmax, ymax;
int computeCode(int x, int y) {
int code = INSIDE;
if (x < xmin) code |= LEFT;
else if (x > xmax) code |= RIGHT;
if (y < ymin) code |= BOTTOM;
else if (y > ymax) code |= TOP;

return code;
}
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
int code1 = computeCode(x1, y1);
int code2 = computeCode(x2, y2);
bool accept = false;
while (true) {
if ((code1 == 0) && (code2 == 0)) {
accept = true;
break;
} else if (code1 & code2) {
break;
} else {
int codeOut;
int x, y;
if (code1 != 0)
codeOut = code1;
else
codeOut = code2;
if (codeOut & TOP) {
x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
y = ymax;
} else if (codeOut & BOTTOM) {
x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
y = ymin;
} else if (codeOut & RIGHT) {
y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
x = xmax;
} else if (codeOut & LEFT) {
y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
x = xmin;
}
if (codeOut == code1) {
x1 = x;
y1 = y;
code1 = computeCode(x1, y1);
} else {
x2 = x;
y2 = y;
code2 = computeCode(x2, y2);
}

}
}
if (accept) {
setcolor(BLUE);
line(x1, y1, x2, y2);
}
}
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm,NULL);
// Set background color to something visible (e.g., green)
setbkcolor(LIGHTGRAY); // Green background
cleardevice(); // Apply the background color

cout << "Enter window coordinates (xmin, ymin, xmax, ymax): ";
cin >> xmin >> ymin >> xmax >> ymax;
rectangle(xmin, ymin, xmax, ymax);
int x1, y1, x2, y2;
cout << "Enter line endpoints (x1, y1, x2, y2): ";
cin >> x1 >> y1 >> x2 >> y2;
setcolor(RED);
line(x1, y1, x2, y2);
cohenSutherlandClip(x1, y1, x2, y2);
getch();
closegraph();
return 0;
}