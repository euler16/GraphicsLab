#ifndef LIBG_H
#define LIBG_H

#include <cmath>
#include <graphics.h>

#define PI 3.14159265
#define SQRT3 1.73205
#define SQRT2 1.41421
#define TORADIAN(theta) ((PI/180)*theta)
#define TODEGREE(x) ((180/PI)*x)

// window size
#define WINX 640
#define WINY 480



class Point2D {
public:
    int x,y;
    Point2D(int i=0,int j=0):x(i),y(j){}
    Point2D mul(const Point2D& P, const float& t);
};

class Point3D {
public:
    int x,y,z;
    Point3D(int i=0,int j=0,int k=0):x(i),y(j),z(k){}
    Point3D mul(const Point3D& P, const float& t);
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

Point3D move3D(const Point3D& P,int dx,int dy, int dz)
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
	float s1coef, s1_coef, s4coef, s4_coef;
	Point3D a;
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




#endif