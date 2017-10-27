#include<iostream>
#include<conio.h>
#include<graphics.h>

using namespace std;

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");


    int x=100,y=100,r=10;
   while(1)
   {
     while(y<200&&!kbhit())
     {
        setcolor(WHITE);
        circle(x,y,r);
        delay(10);
        cleardevice();
        y+=1;


      }
      while(y>100&&!kbhit())
      {

        setcolor(WHITE);
        circle(x,y,r);
        delay(10);
        cleardevice();
        y-=1;

      }

   }









}

