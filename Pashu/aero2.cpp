# include <graphics.h>
# include "lib_graphics.h"

using namespace std;

typedef Point2D Point;
class Aero {
public:
    /* com --> head = 6
       com --> lwing = 4
       com --> rwing = 4*/
    Point com, head, lwing, rwing;
    Aero();
    Aero(Point c,Point h,Point l,Point r):com(c),head(h),lwing(l),rwing(r){}
    void draw();
};

Aero::Aero()
{
    // y increasing downwards
    com = Point(0,0);
    head = Point(30,0);
    lwing = Point(-10,-10*SQRT3);
    rwing = Point(-10,10*SQRT3);
}

void Aero::draw()
{
    line(com.x,com.y,head.x,head.y);
    line(com.x,com.y,lwing.x,lwing.y);
    line(com.x,com.y,rwing.x,rwing.y);
    line(head.x,head.y,lwing.x,lwing.y);
    line(head.x,head.y,rwing.x,rwing.y);
}

void drawX(int x)
{
    // draws the plane at point x
    Aero a;
    float omega = 0.010;

    int y = (getmaxy()/2) + 200*sin(omega*x);
    float angle =  TODEGREE(atan(200*omega*cos(omega*x)));
    a.com = rotate2D(a.com,angle);
    a.head = rotate2D(a.head,angle);
    a.lwing = rotate2D(a.lwing,angle);
    a.rwing = rotate2D(a.rwing,angle);
    
    a.com = move2D(a.com,x,y);
    a.head = move2D(a.head,x,y);
    a.lwing = move2D(a.lwing,x,y);
    a.rwing = move2D(a.rwing,x,y);

    a.draw();
}


int main()
{
    int gd = DETECT, gm;

	initgraph(&gd,&gm,NULL);

    //drawX(140);
    for(int x=100; x<getmaxx()-100; x+=20) {
        drawX(x);
        delay(75);
        cleardevice();
    }

	getch();
	closegraph();
}