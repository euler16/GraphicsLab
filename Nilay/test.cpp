#include "lib_graphics.h"

typedef Point3D point;


void name()
{
   /*  point a(50,80), b(58,40), c(80,40), d(100,80);
    Bezier ee(a,b,c,d);
    ee.Draw();
    //ee.change(2);
    line(100,80,100,150);
    line(60,115,100,115);

    a.set(60,115); b.set(62,120); c.set(64,146); d.set(75,115);
    Bezier n(a,b,c,d);
    n.Draw();
    //n.change(2);
    line(60,115,100,115);
    line(50,80,50,150);
    line(35,80,200,80);
    line(150,80,150,150); */
    /* a.set(60,115); b.set(62,120); c.set(64,146); d.set(75,115);
    Bezier n(a,b,c,d);
    n.Draw(); */
    circle_bres(100,100,20);

}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    name();
    getch();
    closegraph();
}