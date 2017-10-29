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
    void set_point(float first,float second)
    {
      x=first;
      y=second;
      //z=third;
    }
};

Point P[4];

void draw_polygon()
{
  int i;
  //setcolor(RED);
  line(320,0,320,480);
  line(0,240,640,240);

  for(i=0;i<3;i++)
  {
    line(P[i].x,P[i].y,P[(i+1)%3].x,P[(i+1)%3].y);
  }
}

void rot_gen()
{
  int i;
  float angle_deg, angle_rad, cos_term, sin_term;
  cout<<"Enter the angle: "<<endl;
  cin>>angle_deg;

  angle_rad = float((PI*angle_deg)/180);

  cos_term = cos(angle_rad);
  sin_term = sin(angle_rad);

  cout<<sin_term<<" "<<cos_term<<endl;

  setcolor(12);
  draw_polygon();
  for(i=0;i<3;i++)
  {
    P[i].x=(P[i].x)*cos_term - (P[i].y)*sin_term;
    P[i].y=(P[i].x)*sin_term + (P[i].y)*cos_term;
  }
  sleep(2);
  setcolor(15);
  draw_polygon();
}

void main()
{
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  int N,ch;

  cout<<"Enter no. of points"<<endl;
  cin>>N;

  P[0].set_point(0,0);
  P[1].set_point(100,0);
  P[2].set_point(50,50);

  setcolor(WHITE);
  draw_polygon();

  do {
    cout << "\t 2D Transformation";
    cout << "\n\n 1. Rotation about origin \n 2. Rotation about any point \n 3. Translation\n 4. Scaling with no fixed point\n 5. Scaling with fixed point\n 6. Exit";
    cout << "\n\n Enter Choice : ";
    cin >> ch;
    switch (ch) {
    case 1:
      cleardevice();
      rot_gen();
      break;
    case 2:
      //rot_pt();
      break;
    case 3:
      //translation();
      break;
    case 4:
      //scale_gen();
      break;
    case 5:
      //scale_fix();
      break;
    case 6:
      break;
    default:
      cout << "invalid choice ";
    }
  }
  while (ch != 6);

  getch();
  //closegraph();
}