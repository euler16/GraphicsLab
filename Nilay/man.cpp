# include "lib_graphics.h"

typedef Point3D Point;

class Man {
public:
    Point s[20];
    Point t[40];

    Man();
    void draw();
};

Man::Man()
{
    // Face
    s[0] = Point(0,0);
    s[1] = Point(0,75);
    t[0] = Point(-90,10);
    t[1] = Point(90,10);
    t[2] = Point(90,10);
    t[3] = Point(-90,10);

    //left side body
    s[2] = Point(0,80);
    s[3] = Point(-30,190);
    t[4] = Point(-150,5);
    t[5] = Point(0,10);
    s[4] = Point(30,190);
    t[6] = Point(150,5);
    t[7] = Point(0,10);
    t[8] = Point(50,0);
    t[9] = Point(50,0);

    s[5] = Point(-15,100);
    s[6] = Point(-5,180);
    t[10] = Point(-15,20);
    t[11] = Point(5,30);

    s[7] = Point(15,100);
    s[8] = Point(5,180);
    t[12] = Point(15,20);
    t[13] = Point(-5,30);
    t[14] = Point(-10,50);
    t[15] = Point(-10,-50);

    s[9] = Point(-60,300);
    t[16] = Point(-50,50);
    t[17] = Point(-50,50);
    
    s[10] = Point(15,200);
    t[18] = Point(10,30);
    s[11] = Point(-50,300);
    t[19] = Point(-10,10);

    s[12] = Point(5,230);
    s[13] = Point(50,300);
    t[20] = Point(50,50);
    t[21] = Point(50,50);

    s[14] = Point(60,300);
    //s[4]
    t[22] = Point(50,50);
    t[23] = Point(50,50);

    /* s[0] = Point(0,80);
    s[0] = Point();
    s[0] = Point(); */

}

void Man::draw()
{
    draw_herm(s[0],t[0],s[1],t[1]);
    draw_herm(s[0],t[2],s[1],t[3]);
    draw_herm(s[2],t[4],s[3],t[5]);
    draw_herm(s[2],t[6],s[4],t[7]);
    draw_herm(s[3],t[7],s[4],t[8]);
    draw_herm(s[5],t[10],s[6],t[11]);
    draw_herm(s[7],t[12],s[8],t[13]);
    draw_herm(s[6],t[14],s[8],t[15]);
    draw_herm(s[3],t[16],s[9],t[17]);
    draw_herm(s[10],t[18],s[11],t[19]);
    draw_herm(s[12],t[20],s[13],t[21]);
    draw_herm(s[14],t[22],s[4],t[23]);
}

void drawX()
{
    Man m;
    for(int i=0;i<15;++i)
        m.s[i] = move3D(m.s[i],100,100);    
    
    m.draw();
    /* Hermite3D h(m.s[3],m.t[16],m.s[9],m.t[17]);
    h.draw();
    h.change(2); */

}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    drawX();

    getch();
    closegraph();
}