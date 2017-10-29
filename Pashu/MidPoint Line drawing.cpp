#include<conio.h>
#include<iostream.h>
#include<graphics.h>

void put_pixel(int x, int y, int col)
{ 
  putpixel(x+320, 240-y, col);
}
void mid_pt(int x1, int y1, int x2, int y2)
{
  int d;
  float m;
  setcolor(RED);
  line(320,0,320,480);
  setcolor(BLUE);
  line(0,240,640,240);
  setcolor(WHITE);
  if(x2!=x1)
    m=1.0*(y2-y1)/(x2-x1);
  int xa,ya,xb,yb; // Initial(Smaller) point at xa,ya and final point at xb,yb
  if(x1<x2)
  {
    xa=x1;ya=y1;
    xb=x2;yb=y2;  
  }
  else
  {
    xa=x2;ya=y2;
    xb=x1;yb=y1;
  }
  int dx = xb-xa;
  int dy = yb-ya;
  float x = xa, y = ya;
  if( m>=0 && m<=1 )
  {
    put_pixel(xa,ya,15);
    d = 2.0*dy-dx;
    while(x<xb)
    { 
      if(d>0)
      {
      //case NE
        d+=dy-dx;
	      x++;y++;
      }
      else
      {
        d+= dy;
	      x++;  
      }
      put_pixel(x,y,15);   
    }
  }
  else if(m>-1 && m<0)
  { 
    put_pixel(xa,ya,15);
    d = 2.0*dy+dx;
    while(x<xb)
    {
      if(d>0)
      {
      //case E
	     d+=dy;
	     x++; 
      }
      else
      {
        d+= dy+dx;
	      x++;  y--;   
      }
      put_pixel(x,y,15); 
    } 
  }
  else if(m>1)
  {
    put_pixel(xa,ya,15);
    d = dy - 2.0*dx;
    while(x<xb)
  {   
  if(d>0)
    {//case n
      d-= dx;
	    y++; 
    }
  else
    {
      d+= dy-dx;
	    x++;  y++;  
    }
      put_pixel(x,y,15);
    } 
  }
  else if(m<-1)
  { 
    put_pixel(xa,ya,15);
    d = dy + 2.0*dx;
    while(x<xb)
    { 
      if(d>0)
      {  //case se
        d+=dy+dx;
	      x++;y--;
      }
      else
      {
        d+= dx;
        y--; 
      }
      put_pixel(x,y,15);} 
    }
  }

void main()
{
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  int x1,y1,x2,y2;
  cout<<"Enter x1,y1 : ";
  cin>>x1>>y1;
  cout<<"Enter x2,y2 : ";
  cin>>x2>>y2;
  mid_pt(x1,y1,x2,y2);
  getch();
  closegraph();
}
