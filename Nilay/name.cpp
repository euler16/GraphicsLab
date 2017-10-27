#include "lib_graphics.h"

typedef Point3D Point;

void draw_curve(const Point& s1, const Point& s1_, const Point& s4, const Point& s4_)
{
	float s1coef, s1_coef, s4coef, s4_coef;
	Point a;
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

