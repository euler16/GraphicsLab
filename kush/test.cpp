#include<graphics.h>
#include "lib_graphics.h"
#include<iostream>

using namespace std;


class FaceandNeck{
    Point3D s1,s2,s3,s4,s5,s1left_,s1right_,s2left_,s2right_,s3left_,s3right_,s2bottom_,s3bottom_,s4top_,s5top_;
public:
    FaceandNeck(){
        s1.set(0,0,0); //top of face
        s2.set(-30,250,0);//left bottom of face
        s3.set(30,250,0);//right bottom of face
        s4.set(-20,300,0);//left bottom of neck
        s5.set(40,300,0);//right bottom of neck
        s1left_.set(-400,20,0);//left face starting tangent
        s2left_.set(5,0,0);//left face ending tangent
        s1right_.set(400,20,0);//rigth face starting tangent
        s3right_.set(-5,0,0);//right face ending tangent
        s2right_.set(3,50,0);//bottom of face left tangent
        s3left_.set(3,-50,0);//bottom of the face right tangent
        s2bottom_.set(4,10,0);//left neck starting tangent
        s4top_.set(-40,-50,0);//left neck ending tangent
        s3bottom_.set(-4,10,0);
        s5top_.set(40,50,0);
        
    }
    void Draw(){
        //face
        draw_herm(s1,s1left_,s2,s2right_);
        draw_herm(s1,s1right_,s3,s3right_);
        draw_herm(s2,s2right_,s3,s3left_);
        //neck
        draw_herm(s2,s2bottom_,s4,s4top_);
        draw_herm(s3,s3bottom_,s5,s5top_);
    }
};

class UpperbodyandHand{
    Point3D s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
public:
    UpperbodyandHand(){
        s1.set(-20,300,0);//left bottom of neck
        s2.set(40,300,0);//right bottom of neck
        
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    // FaceandNeck faceandneck;
    // faceandneck.Draw();
    //face left
    Point3D a(0,0,0);
    Point3D b(-40,14,0);
    Point3D c(-23,62,0);
    Point3D d(0,75,0);
    Bezier faceleft(a,b,c,d);faceleft.Draw();
    faceleft.change(2);
    //face right

    // a.set(101,10,0);
    // b.set(110,31,0);
    // c.set(115,40,0);
    // d.set(103,50,0);
    // Bezier faceright(a,b,c,d);faceright.Draw();
    // faceright.change(2);
    delay(2000);
    getch();
}
