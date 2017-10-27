#include<iostream>
#include<graphics.h>
#include "lib_graphics.h"

using namespace std;

/*class Point3D {
public:
    int x,y,z;
    Point3D(int i=0,int j=0,int k=0):x(i),y(j),z(k){}
    Point3D mul(const Point3D& P, const float& t);

     void set(int x,int y,int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;

    }

};
*/

int main()
{
    int gd= DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");


    Point3D p[8];
    p[0].set(0,0,0);
    p[1].set(100,0,0);
    p[2].set(100,100,0);
    p[3].set(0,100,0);
    p[4].set(0,0,100);
    p[5].set(100,0,100);
    p[6].set(100,100,100);
    p[7].set(0,100,100);

    line(p[0].x,p[0].y,p[1].x,p[1].y);
    line(p[1].x,p[1].y,p[2].x,p[2].y);
    line(p[2].x,p[2].y,p[3].x,p[3].y);
    line(p[3].x,p[3].y,p[0].x,p[0].y);
    line(p[0].x,p[0].y,p[4].x,p[4].y);
    line(p[4].x,p[4].y,p[7].x,p[7].y);
    line(p[7].x,p[7].y,p[3].x,p[3].y);
    line(p[7].x,p[7].y,p[6].x,p[6].y);
    line(p[6].x,p[6].y,p[2].x,p[2].y);
    line(p[5].x,p[5].y,p[1].x,p[1].y);
    line(p[6].x,p[6].y,p[5].x,p[5].y);
    line(p[4].x,p[4].y,p[5].x,p[5].y);

    cleardevice();

    for(int i=0;i<8;i++)
    {
      p[i]=  move3D(rotate3DX(rotate3DZ(p[i],45.0),TODEGREE(asin(SQRT2/SQRT3))),100,100,100);

    }

    line(p[0].x,p[0].y,p[1].x,p[1].y);
    line(p[1].x,p[1].y,p[2].x,p[2].y);
    line(p[2].x,p[2].y,p[3].x,p[3].y);
    line(p[3].x,p[3].y,p[0].x,p[0].y);
    line(p[0].x,p[0].y,p[4].x,p[4].y);
    line(p[4].x,p[4].y,p[7].x,p[7].y);
    line(p[7].x,p[7].y,p[3].x,p[3].y);
    line(p[7].x,p[7].y,p[6].x,p[6].y);
    line(p[6].x,p[6].y,p[2].x,p[2].y);
    line(p[5].x,p[5].y,p[1].x,p[1].y);
    line(p[6].x,p[6].y,p[5].x,p[5].y);
    line(p[4].x,p[4].y,p[5].x,p[5].y);


    getch();


}
