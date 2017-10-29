#include < iostream.h > 
#include < graphics.h > 
#include < stdio.h > 
#include < conio.h > 
#include < dos.h >

void plotpixel(int x, int y) {
putpixel((x + 300), (240 - y), 15);
putpixel((-x + 300), (240 - y), 15);
putpixel((x + 300), (240 + y), 15);
putpixel((-x + 300), (240 + y), 15);
}
void ellip(int cx, int cy, double a, double b) {
  setcolor(BLUE);
  line(300, 0, 300, 479);
  setcolor(RED);
  line(0, 240, 639, 240);
  double x = 0, y = b; /* initial coorodinates */
  double d1 = 2 * (b * b) + (a * a * (1 - 2 * b));
  plotpixel(x, y);
  while ((a * a * y) >= (b * b * x)) {
    if (d1 <= (a * a * 0.5)) {
      d1 += (4 * b * b * x + 6 * b * b);
      x++;
    } else {
      d1 += ((4 * b * b * x + 6 * b * b) - 4 * a * a * (y - 1));
      x++;
      y--;
    }
    plotpixel(x, y);
  }
  d1 = (b * b * (x + 1) * (x + 1)) + b * b * x * x - 2 * a * a * b * b + 2 * (a * a * (y - 1) * (y - 1));
  while (y >= 0) {
    if (d1 >= (b * b * 0.5)) {
      d1 += 6 * a * a - 4 * a * a * y;
      y--;
    } else {
      d1 += (b * b * 4 * (1 + x)) + 2 * a * a - (4 * a * a * (y - 1));
      x++;
      y--;
    }
    plotpixel(x, y);
  }
}
void main() {
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  double a, b;
  cout << "Enter a and b : ";
  cin >> a >> b;
  ellip(0, 0, a, b);
  getch();
  closegraph();
}