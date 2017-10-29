#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#define LEFT 0x01
#define RIGHT 0x4
#define BOTTOM 0x2
#define TOP 0x8

char getcode(float x, float y, float xwmin, float ywmin, float xwmax, float ywmax) {
  unsigned char code = 0x00;
  if (x < xwmin)
    code = code | LEFT;
  if (x > xwmax)
    code = code | RIGHT;
  if (y > ywmin)
    code = code | BOTTOM;
  if (y < ywmax)
    code = code | TOP;
  return code;
}

void lin(float x1, float y1, float x2, float y2, float xwmin, float ywmin, float xwmax, int ywmax) {
  int done = 0, accept = 0;
  unsigned char code1, code2;
  int gdriver = DETECT, gmode;
  initgraph( & gdriver, & gmode, "c:\\tc\\bgi");
  setcolor(BLUE);
  line(300, 0, 300, 479);
  setcolor(RED);
  line(0, 240, 639, 240);
  setcolor(YELLOW);
  rectangle(xwmin, ywmin, xwmax, ywmax);
  setcolor(GREEN);
  line(x1, y1, x2, y2);
  getch();
  setcolor(WHITE);
  float m;
  while (done == 0) {
    code1 = getcode(x1, y1, xwmin, ywmin, xwmax, ywmax);
    code2 = getcode(x2, y2, xwmin, ywmin, xwmax, ywmax);
    /* case I - accept line */
    if (((code1 & code2) == 0) && ((code1 | code2) == 0)) {
      accept = 1;
      done = 1;
    } else if ((code1 & code2) != 0) {
      done = 1;
      outtextxy(10, 300, "\n Sorry! Line rejected");
    } else {
      if ((x1 >= xwmin && x1 <= xwmax) && (y1 >= ywmax && y1 <= ywmin)) {
        float temp = x1;
        x1 = x2;
        x2 = temp;
        temp = y1;
        y1 = y2;
        y2 = temp;
        char t;
        t = code1;
        code1 = code2;
        code2 = t;
      }
      if (x1 != x2)
        m = (y2 - y1) / (x2 - x1);
      if (code1 & LEFT != 0) {
        y1 += (xwmin - x1) * m;
        x1 = xwmin;
      } else if (code1 & RIGHT) {
        y1 += (xwmax - x1) * m;
        x1 = xwmax;
      } else if (code1 & BOTTOM) {
        if (x2 != x1)
          x1 += (ywmin - y1) / m;
        y1 = ywmin
      } else {
        if (x2 != x1)
          x1 += (ywmax - y1) / m;
        y1 = ywmax;
      }
    }
  }
  if (accept == 1)
    line(x1, y1, x2, y2);
}

void main() {
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  float xwmin, xwmax, ywmin, ywmax;
  cout << " Enter the x limits for the clipping window : ";
  cin >> xwmin >> xwmax;
  cout << "\n Enter the y limits for the clipping window :";
  cin >> ywmin >> ywmax;
  cout << "\n Enter end point 1 : ";
  float x1, y1, x2, y2;
  cin >> x1 >> y1;
  cout << "\n Enter end point 2 : ";
  cin >> x2 >> y2;
  lin(x1 + 300, 240 - y1, x2 + 300, 240 - y2, xwmin + 300, 240 - ywmin, xwmax + 300, 240 - ywmax);
  //  i have interchanged ywmin and ywmax here beacuse we are doing 240-y
  getch();
  closegraph();
}