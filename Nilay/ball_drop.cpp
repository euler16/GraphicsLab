#include "lib_graphics.h"

void anim()
{
    for(int i=0;i<500;++i) {
        circle(100+i,100+10*sqrt(i),10);
        delay(100);
    }
    for(int i=0;i<500;++i) {
        circle(100+i,100+10*i*i,10);
        delay(100);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    anim();
    getch();
    closegraph();
}