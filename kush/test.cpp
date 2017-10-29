#include<graphics.h>
#include "lib_graphics.h"
#include<iostream>

using namespace std;



int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);

    // Point3D a(0,0,0);
    // Point3D b(-40,14,0);
    // Point3D c(-41,78,0);
    // Point3D d(0,75,0);
    
    // Bezier faceleft(a,b,c,d);
    
    // faceleft.Draw();
    // // // faceleft.change(2);
    
    
    // // //face right
    // a.set(-38,190,0);
    // b.set(-45,56,0);
    // c.set(51,59,0);
    // d.set(43,190,0);
    // Bezier chest(a,b,c,d);chest.Draw();
    // // // chest.change(2);
    
    
    // a.set(-38,190,0);
    // b.set(-25,210,0);
    // c.set(20,210,0);
    // d.set(43,190,0);
    // Bezier belt(a,b,c,d);belt.Draw();
    // // // belt.change(2);

    // a.set(27,223,0);
    // b.set(25,239,0);
    // c.set(-12,280,0);
    // d.set(-40,330,0);
    // Bezier legleftright(a,b,c,d);legleftright.Draw();
    // // // legleftright.change(2);

    // a.set(-35,190,0);
    // b.set(-40,210,0);
    // c.set(-57,280,0);
    // d.set(-68,319,0);
    // Bezier legleftleft(a,b,c,d);legleftleft.Draw();
    // // // legleftleft.change(2);

    // a.set(43,190,0);
    // b.set(52,262,0);
    // c.set(59,302,0);
    // d.set(67,333,0);
    // Bezier legrightright(a,b,c,d);legrightright.Draw();
    // // // legrightright.change(2);


    // a.set(6,259,0);
    // b.set(52,341,0);
    // c.set(23,302,0);
    // d.set(40,333,0);
    // Bezier legrightleft(a,b,c,d);
    // legrightleft.Draw();
    

    // a.set(0,0,0);
    // b.set(47,9,0);
    // c.set(34,83,0);
    // d.set(0,75,0);
    // Bezier faceright(a,b,c,d);faceright.Draw();
    // // faceright.change(2);

    // a.set(10,10,0);
    // b.set(47,9,0);
    // c.set(34,83,0);
    // d.set(10,10,0);
    // Bezier hand(a,b,c,d);hand.Draw();
    // hand.change(2);

    Point3D s1(10,10,0);
    Point3D s1_(350,50,0);
    Point3D s2(10,150,0);
    Point3D s2_(150,30,0);

    draw_herm(s1,s1_,s2,s2_);


    delay(2000);
    getch();
}
