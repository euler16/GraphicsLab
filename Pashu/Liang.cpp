#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h> 
#include <conio.h> 
#include <dos.h>

float max(float a, float b, float c, float d) {
  float e, f;
  if (a > b) {
    e = a;
  } else {
    e = b;
  }
  if (c > d) {
    f = c;
  } else {
    f = d;
  }
  if (e > f) {
    return e;
  } else {
    return f;
  }
}

float min(float g, float h, float m, float j) {
  float k, l;
  if (g < h) {
    k = g;
  } else {
    k = h;
  }
  if (m < j) {
    l = m;
  } else {
    l = j;
  }
  if (k < l) {
    return k;
  } else {
    return l;
  }
}

void main() {
  
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  
  float x1, x2, y1, y2, u[4] = {
    0
  }, p[10], i;
  float q[10], dx, dy, xmin, xmax, ymin, ymax;
  float xm, ym, xn, yn;
  cout << "enter x1,y1,x2,y2,xmin,xmax,ymin,ymax";
  cin >> x1 >> y1 >> x2 >> y2 >> xmin >> ymin >> xmax >> ymax >> ymin >> ymax;
  setcolor(BLUE);
  line(320 + xmin, 240 - ymin, 320 + xmax, 240 - ymin);
  line(320 + xmin, 240 - ymin, 320 + xmin, 240 - ymax);
  line(320 + xmax, 240 - ymax, 320 + xmax, 240 - ymin);
  line(320 + xmin, 240 - ymax, 320 + xmax, 240 - ymax);
  setcolor(GREEN);
  line(320 + x1, 240 - y1, 320 + x2, 240 - y2);
  getch();
  dx = x2 - x1;
  dy = y2 - y1;
  p[1] = -dx;
  p[2] = dx;
  p[3] = -dy;
  p[4] = dy;
  q[1] = x1 - xmin;
  q[2] = xmax - x1;
  q[3] = y1 - ymin;
  q[4] = ymax - y1;
  float u1 = 0.0;
  float u2 = 1.0;
  for (i = 1; i <= 4; i++) {
    if (p[i] < 0)
      u[i] = q[i] / p[i];
  }
  u1 = max(u[1], u[2], u[3], u[4]);
  if (u1 < 0) {
    u1 = 0;
  }
  u[1] = 2;
  u[2] = 2;
  u[3] = 2;
  u[4] = 2;
  for (i = 1; i <= 4; i++) {
    if (p[i] > 0)
      u[i] = q[i] / p[i];
  }
  u2 = min(u[1], u[2], u[3], u[4]);
  if (u2 > 1) {
    u2 = 1;
  }
  if (p[1] == 0) {
    if (q[1] < 0 || q[2] < 0) {
      exit(0);
    }
  }
  if (u1 > u2) {
    exit(0);
  }
  xm = x1 + u1 * dx;
  ym = y1 + u1 * dy;
  xn = x1 + u2 * dx;
  yn = y1 + u2 * dy;
  setcolor(WHITE);
  line(320 + xm, 240 - ym, 320 + xn, 240 - yn);
  getch();
}