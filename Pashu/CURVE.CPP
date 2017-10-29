#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

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

void draw_curve(Point s1,Point v1,Point s2,Point v2)
{
	float t,a,b,c,d;
	Point p;
	for(t=0;t<=1;t+=0.001)
	{
		a = 2*t*t*t - 3*t*t + 1;
		b = -2*t*t*t + 3*t*t;
		c = t*t*t - 2*t*t + t;
		d = t*t*t - t*t;
		p.x = a*(s1.x) + b*(s2.x) + c*(v1.x) + d*(v2.x);
		p.y = a*(s1.y) + b*(s2.y) + c*(v1.y) + d*(v2.y);
		putpixel(p.x,p.y,WHITE);
	}
}

void main()
{
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	Point s1,s2,v1,v2;

	s1.anything(140,140);
	s2.anything(140,180);
	v1.anything(-60,-20);
	v2.anything(60,60);

	draw_curve(s1,v1,s2,v2);

	getch();
}