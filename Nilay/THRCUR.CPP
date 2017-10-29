# include <graphics.h>
//# include <conio.h>

class Point {

	public:
	    float x;
	    float y;

	    Point (int i = 0, int j = 0): x(i), y(j) {} ;

};

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

int main()
{
	int gd = DETECT, gm;
	int polygon[10];


	// initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	initgraph(&gd,&gm,NULL);
/*     Point s1(10,50);
    Point s1_(-100,30);   // for S
    Point s4(10,100);
	Point s4_(-100,30);

	draw_curve(s1,s1_,s4,s4_);
 */	
	/* draw_curve(Point(10,50),Point(100,0),Point(10,100),Point(-100,0));
	line(10,50,10,150);
	line(10,100,40,150);         // for R */
	
	draw_curve(Point(50,10+50),Point(-150,20),Point(100,50+50),Point(50,0));
	draw_curve(Point(50,10+50),Point(150,20),Point(10,100+50),Point(-20,20));
	draw_curve(Point(100,50+50),Point(-60,100),Point(40,140+50),Point(-60,100));
	draw_curve(Point(100,10+50),Point(0,140),Point(100,150+50),Point(0,-140));
	draw_curve(Point(100+30,10+50),Point(0,140),Point(100+30,150+50),Point(0,-140));
	draw_curve(Point(100,10+50),Point(-200,-200),Point(100+30,10+50),Point(-200,200));
	draw_curve(Point(75,10+50),Point(70,0),Point(140,10+50),Point(70,0));	   // shri in HINDI


	draw_curve(Point(75,10+50),Point(70,0),Point(140,10+50),Point(70,0));


	getch();
	closegraph();

	return 0;
}