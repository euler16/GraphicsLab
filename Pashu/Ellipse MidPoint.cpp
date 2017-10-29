#include < iostream.h > 
#include < graphics.h > 
#include < stdio.h > 
#include < conio.h > 
#include < dos.h >

void plotpixel(int x, int y) {
  delay(10);
  putpixel((x + 320), (240 - y), 15);
  putpixel((-x + 320), (240 - y), 15);
  putpixel((x + 320), (240 + y), 15);
  putpixel((-x + 320), (240 + y), 15);
}

void ell(float a, float b) {
  float x = 0, y = b;
  float d = a * a * (0.25 - b) + b * b;
  setcolor(RED);
  line(320, 0, 320, 480);
  setcolor(BLUE);
  line(0, 240, 640, 240);
  setcolor(WHITE);
  plotpixel(x, y);
  while ((b * b * (x + 1)) <= (a * a * (y - 0.5))) {
    if (d < 0) {
      d += 1.0 * b * b * (3 + 2 * x);
      x++;
    } else {
      d += b * b * (3 + 2 * x) * 1.0 + 2 * 1.0 * a * a * (1 - y);
      x++;
      y--;
    }
    plotpixel(x, y);
  }
  d = b * b * (1.0 * x + 0.5) * (1.0 * x + 0.5) + 1.0 * a * a * (y - 1) * (y - 1) - 1.0 * a * a * b * b;
  while (y >= 0) {
    if (d < 0) {
      d += 2.0 * b * b * (1 + x) + 1.0 * a * a * (3 - 2 * y);
      x++;
      y--;
    } else {
      d += a * a * (3 - 2 * y) * 1.0;
      y--;
    }
    plotpixel(x, y);
  }
}
void main() {
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  float a, b;
  cout << "Enter a & b : ";
  cin >> a >> b;
  ell(a, b);
  getch();
  closegraph();
}