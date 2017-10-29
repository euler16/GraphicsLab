#include<graphics.h>
#include "lib_graphics.h"
#include<iostream>

using namespace std;

void draw(){
    for(int x = -150 ; x<=150;x++){
        int y = (x*x)/100;
        
        putpixel(x+WINX/2,400-y,2);
    }
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);

    
    
    int radius = 20;

    // circle(-150+WINX/2,400-225,5);
    for(int y = 225; y>=0;y--){
        int x = -1*sqrt(100*y);
        cout<<x;
        int cirx;
        int ciry;
        if(x!=0){
            float normslope = -100/(2.0*x);
            float c = y - normslope*x;
            float increment = (float)radius/(sqrt(1+normslope*normslope))+1;
            // cout<<"  "<<increment;
            cirx = x+increment;
            ciry = y+normslope*increment;
        }else{
            cirx = 0;
            ciry = radius;
        }
        // cout<<" "<<cirx<<" "<<ciry;
        setcolor(2);
        circle(cirx+WINX/2,400-ciry,radius);
        delay(20);
           setcolor(0);
           circle(cirx+WINX/2,400-ciry,radius);
        //    setcolor(2);
        //    putpixel(x+WINX/2,400-y,2);
            // draw();
    }

    for(int y = 0; y<255;y++){
        int x = sqrt(100*y);
        cout<<x;
        int cirx;
        int ciry;
        if(x!=0){
            float normslope = -100/(2.0*x);
            float c = y - normslope*x;
            float increment = (float)radius/(sqrt(1+normslope*normslope));
            // cout<<"  "<<increment;
            cirx = x-increment;
            ciry = y-normslope*increment;
        }else{
            cirx = 0;
            ciry = radius;
        }
        // cout<<" "<<cirx<<" "<<ciry;
        setcolor(2);
        circle(cirx+WINX/2,400-ciry,radius);
           delay(30);
           setcolor(0);
           circle(cirx+WINX/2,400-ciry,radius);
           setcolor(2);
        //    putpixel(x+WINX/2,400-y,2);
            draw();
    }


    delay(2000);
    getch();

}