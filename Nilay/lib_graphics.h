#ifndef LIBG_H
#define LIBG_H

#include <cmath>
#include <graphics.h>
#include <iostream>

#define PI 3.14159265
#define SQRT3 1.73205
#define SQRT2 1.41421
#define TORADIAN(theta) ((PI/180)*theta)
#define TODEGREE(x) ((180/PI)*x)

// window size
#define WINX 640
#define WINY 480

using namespace std;

class Point2D {
public:
    int x,y;
    Point2D(int i=0,int j=0):x(i),y(j){}
    Point2D mul(const Point2D& P, const float& t);
    void set(int i=0,int j=0){x=i,y=j;}
};

class Point3D {
public:
    int x,y,z;
    Point3D(int i=0,int j=0,int k=0):x(i),y(j),z(k){}
    Point3D mul(const Point3D& P, const float& t);
    void set(int i=0,int j=0,int k=0){x=i,y=j,z=k;}
    void set(Point3D d){
        this->x = d.x;
        this->y = d.y;
        this->z = d.z;
    }
};

class Hermite3D {
public:
    Point3D control[4]; // s1, t1, s2, t2
    int color;
    Hermite3D(const Point3D&,const Point3D& ,const Point3D&,const Point3D&);
    void draw();
    void change(int);
};

class Bezier {
    Point3D s[4]; // control points
    int color;
    int ca[4];    // nCr
public:
    Bezier(Point3D a,Point3D b,Point3D c,Point3D d){
        // cout<<"in const";
        this->s[0].set(a);
        this->s[1].set(b);
        this->s[2].set(c);
        this->s[3].set(d);
        ca[0] = 1;
        ca[1] = 3;
        ca[2] = 3;
        ca[3] = 1;
        color = 2;
    }

    void Draw(){
        // cout<<"here";
        for(float u = 0;u<=1;u+=0.01){
            Point3D toplot(0,0,0);
            // cout<<"inside here here";
            for(int i =0 ;i<4;i++){
                
                float temp = ca[i]*(float)pow(u,i)*(float)pow(1-u,3-i);
                // cout<<"temp"<<temp<<endl;
                toplot.x+=s[i].x*temp;
                toplot.y+=s[i].y*temp;
                toplot.z+=s[i].z*temp;
            }
            // cout<<"put pixel karne waala hoon";
            // cout<<toplot.x<<" and "<<toplot.y<<endl;
            putpixel(toplot.x,toplot.y,this->color);
            // putpixel(10,10,1);
            // putpixel(11,10,1);
            // putpixel(12,10,1);
            // putpixel(13,10,1);
            // putpixel(14,10,1);
        }
    }

    void change(int point){
        
            char c;
            while(true){
                // cout<<"waiting for input";
                // circle(s[point-1].x,s[point-1].y,5);
                //char c;
                cin>>c;
                // cout<<"c is"<<c;
                if(c == 'w'){
                    this->color = 0;
                    this->Draw();
                    s[point-1].y--;
                    
                    this->color = 2;
                    this->Draw();
                }
                else if(c == 'a'){
                    this->color = 0;
                    this->Draw();
                    s[point-1].x--;
                    this->color = 2;
                    this->Draw();
                }
                else if(c == 'd'){
                    this->color = 0;
                    this->Draw();
                    s[point-1].x++;
                    this->color = 2;
                    this->Draw();
                }
                else if(c == 's'){
                    this->color = 0;
                    this->Draw();
                    s[point-1].y++;
                    this->color = 2;
                    this->Draw();
                }
                else{
                    cout<<"enter the point number you want number";
                    int n;
                    cin>>n;
                    if(n<=4&&n>=1){
                        point = n;
                    }else{

                        cout<<endl<<endl<<"your points should be"<<endl;
                        cout<<"a "<<s[0].x <<"   "<<s[0].y<<endl;
                        cout<<"b "<<s[1].x <<"   "<<s[1].y<<endl;
                        cout<<"c "<<s[2].x <<"   "<<s[2].y<<endl;
                        cout<<"d "<<s[3].x <<"   "<<s[3].y<<endl;

                        break;
                    }
                }
            }
        
    }
};

void matmul(float A[][10],float B[][10],float C[][10],int A_r,int A_c,int B_r,int B_c);

// translation
// not inplace
Point2D move2D(const Point2D& P,int dx,int dy);
Point3D move3D(const Point3D& P,int dx,int dy,int dz);


// 2D rotation
// these are inplace ops
void rotate2D(float A[3][10],float prod[][10],float angle,int c);
inline void rotate2D(int &x,int &y, float angle);

// not inplace
Point2D rotate2D(const Point2D &P,float angle);

// 3D rotations
Point3D rotate3DX(const Point3D& P, float angle);
Point3D rotate3DY(const Point3D& P, float angle);
Point3D rotate3DZ(const Point3D& P, float angle);

void draw_herm(const Point3D& s1,const Point3D& s1_,const Point3D& s4,const Point3D& s4_);

// Point 2D class definations
Point2D Point2D::mul(const Point2D& P,const float& t)
{  
    return Point2D(P.x*t,P.y*t);
}



// Point 3D class definations
Point3D Point3D::mul(const Point3D& P,const float& t)
{  
    return Point3D(P.x*t,P.y*t,P.z*t);
}



void matmul(float A[][10],float B[][10],float C[][10],int A_r,int A_c,int B_r,int B_c)
{
    int i,j,k;
    for(i=0; i<A_r; ++i) {
        for(j=0; j<B_c; ++j) {
            C[i][j] = 0;
            for(k=0; k<A_c; ++k)
                C[i][j] += A[i][k]*B[k][j];
        }
    }
}

// translation functions
Point2D move2D(const Point2D& P,int dx,int dy)
{
    return Point2D(P.x+dx,P.y+dy);
}

Point3D move3D(const Point3D& P,int dx,int dy, int dz=0)
{
    return Point3D(P.x+dx,P.y+dy,P.z+dz);
}


// rotate functions
// Matrix version
void rotate2D(float A[2][10],float trans[][10],float angle,int c)
{
    
    // c is the number of column vectors in A
    // not working
    float x = TORADIAN(angle);
    float R[2][10] = {
                        {cos(x), -sin(x)},
                        {sin(x), cos(x)}
                    };

    matmul(R,A,trans,2,2,2,c);
}
// direct variables
inline void rotate2D(const int &x,const int &y,int &x_,int &y_, float angle)
{
    float rad = TORADIAN(angle);
    float cs = cos(rad), sn = sin(rad);
    x_ = x*cs - y*sn;
    y_ = x*sn + y*cs;
}
// point class
Point2D rotate2D(const Point2D& P,float angle)
{
    int x_,y_;
    rotate2D(P.x,P.y,x_,y_,angle);
    return Point2D(x_,y_);
}

Point3D rotate3DX(const Point3D& P, float angle)
{
    Point3D Q;
    float x = TORADIAN(angle);
    Q.x = P.x;
    Q.y = P.y*cos(x) - P.z*sin(x);
    Q.z = P.y*sin(x) + P.z*cos(x);

    return Q;
}

Point3D rotate3DY(const Point3D& P, float angle)
{
    Point3D Q;
    float x = TORADIAN(angle);
    Q.y = P.y;
    Q.x = P.x*cos(x) + P.z*sin(x);
    Q.z = P.z*cos(x) - P.x*sin(x);

    return Q;
}

Point3D rotate3DZ(const Point3D& P, float angle)
{
    Point3D Q;
    float x = TORADIAN(angle);
    Q.z = P.z;
    Q.x = P.x*cos(x) - P.y*sin(x);
    Q.y = P.x*sin(x) + P.y*cos(x);

    return Q;
}

void draw_herm(const Point3D& s1,const Point3D& s1_,const Point3D& s4,const Point3D& s4_)
{
    // s1_ and s4_ are tangents
	float s1coef, s1_coef, s4coef, s4_coef;
	Point3D a;
	for(float t=0; t<=1.0; t+=0.001) {
		s1coef = 2*t*t*t - 3*t*t + 1;
		s1_coef = t*t*t - 2*t*t + t;
		s4coef = -2 * t*t*t + 3*t*t;
		s4_coef = t*t*t - t*t;
	
		a.x = s1.x*s1coef + s1_.x*s1_coef + s4.x*s4coef + s4_.x*s4_coef;
        a.y = s1.y*s1coef + s1_.y*s1_coef + s4.y*s4coef + s4_.y*s4_coef;
        a.z = s1.z*s1coef + s1_.z*s1_coef + s4.z*s4coef + s4_.z*s4_coef;
		putpixel(a.x,a.y,1);
	}
}

void draw_herm(const Point2D& s1,const Point2D& s1_,const Point2D& s4,const Point2D& s4_)
{
    // s1_ and s4_ are tangents
	float s1coef, s1_coef, s4coef, s4_coef;
	Point2D a;
	for(float t=0; t<=1.0; t+=0.001) {
		s1coef = 2*t*t*t - 3*t*t + 1;
		s1_coef = t*t*t - 2*t*t + t;
		s4coef = -2 * t*t*t + 3*t*t;
		s4_coef = t*t*t - t*t;
	
		a.x = s1.x*s1coef + s1_.x*s1_coef + s4.x*s4coef + s4_.x*s4_coef;
		a.y = s1.y*s1coef + s1_.y*s1_coef + s4.y*s4coef + s4_.y*s4_coef;
		putpixel(a.x,a.y,1);
	}
}

Hermite3D::Hermite3D(const Point3D&s1,const Point3D&t1,const Point3D&s2,const Point3D&t2)
{
    control[0] = s1;
    control[1] = t1;
    control[2] = s2;
    control[3] = t2; 
}

void Hermite3D::draw()
{
    float s1coef, s1_coef, s4coef, s4_coef;
	Point3D a;
	for(float t=0; t<=1.0; t+=0.001) {
		s1coef = 2*t*t*t - 3*t*t + 1;
		s1_coef = t*t*t - 2*t*t + t;
		s4coef = -2 * t*t*t + 3*t*t;
		s4_coef = t*t*t - t*t;
	
		a.x = control[0].x*s1coef+control[1].x*s1_coef+control[2].x*s4coef+control[3].x*s4_coef;
        a.y = control[0].y*s1coef+control[1].y*s1_coef+control[2].y*s4coef+control[3].y*s4_coef;
        a.z = control[0].z*s1coef+control[1].z*s1_coef+control[2].z*s4coef+control[3].z*s4_coef;
		putpixel(a.x,a.y,color);
	}
}

void Hermite3D::change(int c)
{
    int kb;
    while(kb=getchar()) {
        switch(kb) {
            case 'a': color=0; draw();
                      control[c-1].x--;
                      color=2;draw();
                      break;
            case 'd': color=0; draw();
                      control[c-1].x++;
                      color=2;draw();
                      break;
            case 'w': color=0; draw();
                      control[c-1].y--;
                      color=2;draw();
                      break;
            case 's': color=0; draw();
                      control[c-1].y++;
                      color=2;draw();
                      break;
            default: cout<<"Enter the new control: ";
                     cin>>c;
                     if (c<=4 and c>=1) {
                         continue;
                     }
                     else {
                         cout<<"The required control points are"<<endl;
                         cout<<control[0].x<<" "<<control[0].y<<endl;
                         cout<<control[1].x<<" "<<control[1].y<<endl;
                         cout<<control[2].x<<" "<<control[2].y<<endl;
                         cout<<control[3].x<<" "<<control[3].y<<endl;
                         goto loop_exit;
                     }
        }
    }
    loop_exit: ;
}


void plotpixel(int x,int y,int xc,int yc,int dx=320,int dy=240,int color=15) {
    // delay(20);
    putpixel((x + xc + dx), (dy - y - yc), color);
    putpixel((-x + xc + dx), (dy - y - yc), color);
    putpixel((x + xc + dx), (dy + y - yc), color);
    putpixel((-x + xc + dx), (dy + y - yc), color);
    putpixel((y + xc + dx), (dy - yc - x), color);
    putpixel((-y + xc + dx), (dy - yc - x), color);
    putpixel((y + xc + dx), (dy - yc + x), color);
    putpixel((-y + xc + dx), (dy - yc + x), color);
  }
  void circle_bres(int xc,int yc,int r) {
    // Bresenham
    int x = 0, y = r;
    float d = 3 - 2 * r;
    // setcolor(RED);
    // line(320, 0, 320, 480);
    // setcolor(BLUE);
    // line(0, 240, 640, 240);
    
    setcolor(WHITE);
    plotpixel(x, y, xc, yc);
    while (x <= y) {
      if (d < 0) {
        d += 6 + 4 * x;
        x++;
      } else {
        d += 10 + 4 * (x - y);
        x++;
        y--;
      }
      plotpixel(x, y, xc, yc);
    }
  }


#endif