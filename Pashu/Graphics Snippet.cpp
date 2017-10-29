#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <dos.h>

//Dimensions are from x=0 to x=640 and y=0 to y=480

#define PI 3.14159

class Point
{
  public:
    float x;
    float y;
    //float z;
    void anything(float first,float second)
    {
      x=first;
      y=second;
      //z=third;
    }
};

void put_pixel(int x, int y, int col)
{ 
  putpixel(x+320, 240-y, col);
}

//Circle Plotting
void plotpixel_circle(int x, int y, int xc, int yc) {
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

void draw_polygon()
{
  int i;
  for(i=0;i<=3;i++)
  {
    line(P[i].x,P[i].y,P[(i+1)%3].x,P[(i+1)%3].y);
  }
}

void plotpixel_ellipse(int x, int y) {
  delay(10);
  putpixel((x + 320), (240 - y), 15);
  putpixel((-x + 320), (240 - y), 15);
  putpixel((x + 320), (240 + y), 15);
  putpixel((-x + 320), (240 + y), 15);
}

void main()
{
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  
  getch();
  closegraph();
}