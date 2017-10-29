#include "lib_graphics.h"


void anim()
{
    int r=20,y,x,cx,cy;
    float n_slope = 0;
    int flip = 1;
    float angle = 0;
    int stangle = 0;
    for(int t=-150;t<150; ++t) {
        if(t==0) flip = -1;
        stangle += 4;
        y = 400-((t*t)/100);
        x = 200+t;
        n_slope = (-50)/(t+0.001);
        
        setcolor(WHITE);    
        cx = x + flip*(r+2)*cos(atan(n_slope));
        cy = y - flip*(r+2)*sin(atan(n_slope));
        arc(cx,cy,stangle,stangle+180,r);
        setcolor(GREEN);
        arc(cx,cy,stangle+180,stangle+360,r);
        putpixel(x,y,1);
        delay(100);
        setcolor(BLACK);
        arc(cx,cy,stangle,stangle+180,r);
        arc(cx,cy,stangle+180,stangle+360,r);
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