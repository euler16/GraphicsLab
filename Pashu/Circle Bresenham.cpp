#include < iostream.h > 
#include < graphics.h > 
#include < stdio.h > 
#include < conio.h > 
#include < dos.h >

void plotpixel(int x,int y,int xc,int yc,int dx=320,int dy=240,int color=15) {
  // delay(20);
  putpixel((x + xc + dx), (dy - y - yc), color);
  putpixel((-x + xc + dx), (dy - y - yc), color);
  putpixel((x + xc + dx), (dy + y - yc), color);
  putpixel((-x + xc + dx), (dy + y - yc), color);
  putpixel((y + xc + dx), (dy - yc - x), color);
  putpixel((-y + xc + dx), (dy - yc - x), color);
  putpixel((y + xc + dx), (dy - yc + x), color);
  putpixel((-y + xc + dx), (dy - yc + x), color);
}

void circle(int r, int xc, int yc) {
  // Bresenham
  int x = 0, y = r;
  float d = 3 - 2 * r;
  // setcolor(RED);
  // line(320, 0, 320, 480);
  // setcolor(BLUE);
  // line(0, 240, 640, 240);
  
  setcolor(WHITE);
  plotpixel(x, y, xc, yc);
  while (x <= y) {
    if (d < 0) {
      d += 6 + 4 * x;
      x++;
    } else {
      d += 10 + 4 * (x - y);
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