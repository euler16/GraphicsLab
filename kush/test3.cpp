#include<graphics.h>
#include "lib_graphics.h"
#include<iostream>

using namespace std;




int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    outtextxy(100, 100, "Hi There");
    delay(2000);
    getch();

}