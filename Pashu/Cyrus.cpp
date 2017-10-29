#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h> 
#include <conio.h> 
#include <dos.h>

struct point {
  float x, y;
};

void clip(point pol[10], point p1, point p2, int n) {
  cleardevice();
  setcolor(BLUE);
  line(320, 0, 320, 480);
  setcolor(RED);
  line(0, 240, 640, 240);
  setcolor(YELLOW);
  for (int i = 0; i < n; i++) {
    line(pol[i].x, pol[i].y, pol[i + 1].x, pol[i + 1].y);
  }
  setcolor(WHITE);
  line(p1.x, p1.y, p2.x, p2.y);
  getch();
  float t_enter = 0, t_leave = 1;
  for (i = 0; i < n; i++) {
    point n, pei;
    pei = pol[i];
    n.x = (pol[i + 1].y - pol[i].y);
    n.y = (pol[i + 1].x - pol[i].x);
    float num, den;
    num = n.x * (pei.x - p1.x) - n.y * (pei.y - p1.y);
    den = n.x * (p2.x - p1.x) + n.y * (p1.y - p2.y);
    float t;
    if (den != 0)
      t = num * 1.0 / den;
    if (t >= 0 && t <= 1) {
      if (den < 0) {
        if (t > t_enter)
          t_enter = t;
      } else if (den > 0) {
        if (t < t_leave)
          t_leave = t;
      }
    }
  }
  point pi, pl;
  pi.x = p1.x + (p2.x - p1.x) * t_enter;
  pi.y = p1.y + (p2.y - p1.y) * t_enter;
  pl.x = p1.x + (p2.x - p1.x) * t_leave;
  pl.y = p1.y + (p2.y - p1.y) * t_leave;
  setcolor(GREEN);
  line(pi.x, pi.y, pl.x, pl.y);
}

void main() {
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  cout << "Enter the no. of vertices of clipping window : ";
  int n;
  cin >> n;
  point pol[10];
  cout << "Enter the vertices in clockwise order \n";
  for (int i = 0; i < n; i++) {
    cout << " Enter vertex : ";
    cin >> pol[i].x >> pol[i].y;
    pol[i].x += 320;
    pol[i].y = 240 - pol[i].y;
  }
  pol[i].x = pol[0].x;
  pol[i].y = pol[0].y;
  cout << "Enter the end points of the line : ";
  point p1, p2;
  cin >> p1.x >> p1.y >> p2.x >> p2.y;
  int t;
  if (p1.x > p2.x) {
    t = p1.x;
    p1.x = p2.x;
    p2.x = t;
    t = p1.y;
    p1.y = p2.y;
    p2.y = t;
  }
  p1.x += 320;
  p2.x += 320;
  p1.y = 240 - p1.y;
  p2.y = 240 - p2.y;
  clip(pol, p1, p2, n);
  
  getch();
  closegraph();
}