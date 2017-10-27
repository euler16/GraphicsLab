#include "lib_graphics.h"

#define PHI (asin(SQRT2/SQRT3))

class Cube {
public:
    Point3D v1,v2,v3,v4,v5,v6,v7,v8;
    Cube();
    void draw();
};
Cube::Cube()
{
    v1 = Point3D(0,0,0);
    v2 = Point3D(100,0,0);
    v3 = Point3D(100,100,0);
    v4 = Point3D(0,100,0);
    v5 = Point3D(0,0,100);
    v6 = Point3D(100,0,100);
    v7 = Point3D(100,100,100);
    v8 = Point3D(0,100,100);
}
void Cube::draw()
{
    // front view
    line(v1.x,v1.y,v2.x,v2.y);
    line(v2.x,v2.y,v3.x,v3.y);
    line(v3.x,v3.y,v4.x,v4.y);
    line(v4.x,v4.y,v1.x,v1.y);

    line(v5.x,v5.y,v6.x,v6.y);
    line(v6.x,v6.y,v7.x,v7.y);
    line(v7.x,v7.y,v8.x,v8.y);
    line(v8.x,v8.y,v5.x,v5.y);

    line(v1.x,v1.y,v5.x,v5.y);
    line(v2.x,v2.y,v6.x,v6.y);
    line(v3.x,v3.y,v7.x,v7.y);
    line(v4.x,v4.y,v8.x,v8.y);
}

void isometric()
{
    Cube c;
    //c.draw();
    c.v1 = rotate3DZ(c.v1,45);
    c.v2 = rotate3DZ(c.v2,45);
    c.v3 = rotate3DZ(c.v3,45);
    c.v4 = rotate3DZ(c.v4,45);
    c.v5 = rotate3DZ(c.v5,45);
    c.v6 = rotate3DZ(c.v6,45);
    c.v7 = rotate3DZ(c.v7,45);
    c.v8 = rotate3DZ(c.v8,45);

    c.v1 = rotate3DX(c.v1,TODEGREE(PHI));
    c.v2 = rotate3DX(c.v2,TODEGREE(PHI));
    c.v3 = rotate3DX(c.v3,TODEGREE(PHI));
    c.v4 = rotate3DX(c.v4,TODEGREE(PHI));
    c.v5 = rotate3DX(c.v5,TODEGREE(PHI));
    c.v6 = rotate3DX(c.v6,TODEGREE(PHI));
    c.v7 = rotate3DX(c.v7,TODEGREE(PHI));
    c.v8 = rotate3DX(c.v8,TODEGREE(PHI));

    c.v1 = move3D(c.v1,100,100,0);
    c.v2 = move3D(c.v2,100,100,0);
    c.v3 = move3D(c.v3,100,100,0);
    c.v4 = move3D(c.v4,100,100,0);
    c.v5 = move3D(c.v5,100,100,0);
    c.v6 = move3D(c.v6,100,100,0);
    c.v7 = move3D(c.v7,100,100,0);
    c.v8 = move3D(c.v8,100,100,0);

    c.draw();
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    isometric();
    getch();
    closegraph();

    return 0;
}