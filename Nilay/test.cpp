#include "lib_graphics.h"

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);

    //draw_herm()
    Point3D a(100,100), b(10,15), c(100,150), d(-10,-15);
    draw_herm(b,b,c,d);
    Hermite3D h(a,b,c,d);
    h.draw();
    h.change(2);

    getch();
    closegraph();
}