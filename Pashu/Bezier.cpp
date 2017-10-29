#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <dos.h>

void bezier();

void main() {
  clrscr();	
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  bezier();
}
void bezier() {
  float p1[3], p2[3], p3[3], p4[3], temp[3];
  cout << "\n enter the coords of P1 \n";
  cin >> p1[0] >> p1[1] >> p1[2];
  cout << "\n enter the coords of P2 \n";
  cin >> p2[0] >> p2[1] >> p2[2];
  cout << "\n enter the coords of P3 \n";
  cin >> p3[0] >> p3[1] >> p3[2];
  cout << "\n enter the coords of P4  \n";
  cin >> p4[0] >> p4[1] >> p4[2];
  temp[0] = p1[0];
  temp[1] = p1[1];
  temp[2] = p1[2];
  cleardevice();
  for (float t = .001; t <= 1; t += .001) {
    temp[0] = (1 - t) * (1 - t) * (1 - t) * p1[0] + (3 * t * (1 - t) * (1 - t)) * p2[0] + ((3 * t * t) * (1 - t)) * p3[0] + ((t * t * t)) * p4[0];
    temp[1] = (1 - t) * (1 - t) * (1 - t) * p1[1] + (3 * t * (1 - t) * (1 - t)) * p2[1] + ((3 * t * t) * (1 - t)) * p3[1] + ((t * t * t)) * p4[1];
    temp[2] = (1 - t) * (1 - t) * (1 - t) * p1[2] + (3 * t * (1 - t) * (1 - t)) * p2[2] + ((3 * t * t) * (1 - t)) * p3[2] + ((t * t * t)) * p4[2];
    putpixel(temp[0], temp[1], BLUE);
  }
  setcolor(WHITE);
  line(p1[0], p1[1], p2[0], p2[1]);
  line(p2[0], p2[1], p3[0], p3[1]);
  line(p3[0], p3[1], p4[0], p4[1]);
  line(p1[0], p1[1], p4[0], p4[1]);
  getch();
}