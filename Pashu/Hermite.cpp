#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <dos.h>

struct pt {
  float x, y;
  float mx, my;
};
struct pt g1, g2;
void main() {
  float outx, outy, u, gx[4], gy[4], tempx[4], tempy[4];
  cout << "Enter the x-co-ord of first point: ";
  cin >> g1.x;
  cout << "\n\nEnter the y-co-ord of first point: ";
  cin >> g1.y;
  cout << "\n\nEnter the x-co-ord of second point: ";
  cin >> g2.x;
  cout << "\n\nEnter the y-co-ord of the second point: ";
  cin >> g2.y;
  cout << "Enter the x-co-ord of the tangent vector at first end point";
  cin >> g1.mx;
  cout << "Enter the tangent vector's y co-ord at first end point: ";
  cin >> g1.my;
  cout << "Enter the tangent vector's x-co-ord at second end point: ";
  cin >> g2.mx;
  cout << "Enter the tangent vector's y-co-ord at second end point: ";
  cin >> g2.my;

  int gd = DETECT, gm;
  initgraph( & gd, & gm, "C:\\TURBOC3\\BGI");

  gx[0] = g1.x;
  gx[1] = g2.x;
  gx[2] = g1.mx;
  gx[3] = g2.mx;
  gy[0] = g1.y;
  gy[1] = g2.y;
  gy[2] = g1.my;
  gy[3] = g2.my;
  tempx[0] = 2 * (gx[0] - gx[1]) + gx[2] + gx[3];
  tempx[1] = -3 * (gx[0] - gx[1]) - 2 * gx[2] - gx[3];
  tempx[2] = gx[2];
  tempx[3] = gx[0];
  tempy[0] = 2 * (gy[0] - gy[1]) + gy[2] + gy[3];
  tempy[1] = -3 * (gy[0] - gy[1]) - 2 * gy[2] - gy[3];
  tempy[2] = gy[2];
  tempy[3] = gy[0];
  setcolor(RED);
  line(0, 240, 640, 240);
  setcolor(BLUE);
  line(320, 0, 320, 480);
  setcolor(WHITE);
  for (u = 0; u <= 1; u += 0.0001) {
    outx = u * u * u * tempx[0] + u * u * tempx[1] + u * tempx[2] + tempx[3];
    outy = u * u * u * tempy[0] + u * u * tempy[1] + u * tempy[2] + tempy[3];
    putpixel(320 + outx, 240 - outy, 15);
  }
  getch();
}