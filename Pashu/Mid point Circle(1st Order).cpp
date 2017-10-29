#include < iostream.h > 
#include < graphics.h > 
#include < stdio.h > 
#include < conio.h > 
#include < dos.h >

void plotpixel(int x, int y, int xc, int yc) {
  delay(20);
  putpixel((x + xc + 320), (240 - y - yc), 15);
  putpixel((-x + xc + 320), (240 - y - yc), 15);
  putpixel((x + xc + 320), (240 + y - yc), 15);
  putpixel((-x + xc + 320), (240 + y - yc), 15);
  putpixel((y + xc + 320), (240 - yc - x), 15);
  putpixel((-y + xc + 320), (240 - yc - x), 15);
  putpixel((y + xc + 320), (240 - yc + x), 15);
  putpixel((-y + xc + 320), (240 - yc + x), 15);
}

void circ(int r, int xc, int yc) {
  float x = 0, y = r;
  float d = 1 - r;
  setcolor(RED);
  line(320, 0, 320, 480);
  setcolor(BLUE);
  line(0, 240, 640, 240);
  setcolor(WHITE);
  plotpixel(x, y, xc, yc);
  while (x <= y) {
    if (d < 0) {
      d += 3 + 2 * x;
      x++;
    } else {
      d += 5 + 2 * (x - y);
      x++;
      y--;
    }
    plotpixel(x, y, xc, yc);
  }
}

void main() {
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  int xc, yc;
  cout << "Enter co-ordinates of center : ";
  cin >> xc >> yc;
  int r; //radius
  cout << "Enter the radius : ";
  cin >> r;
  circ(r, xc, yc);
  getch();
  closegraph();
}