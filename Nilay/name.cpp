#include "lib_graphics.h"

typedef Point3D Point;

class McD {
public:
	Point3D s[10];
	Point3D t[10];
	McD();
	void draw();
};

McD::McD()
{
	s[0] = Point(-75,150);
	s[1] = Point(0,85);
	s[2] = Point(75,150);

	t[0] = Point(10,-570);
	t[1] = Point(15,130);

	t[2] = Point(15,-130);
	t[3] = Point(10,570);
}

void McD::draw()
{
	draw_herm(s[0],t[0],s[1],t[1]);
	draw_herm(s[1],t[2],s[2],t[3]);
}

void anim()
{
	for(int i=0; i<360; i+=10) {
		McD m;
		m.s[0] = move3D(rotate3DY(m.s[0],i),getmaxx()/2,getmaxy()/2,0);
		m.s[1] = move3D(rotate3DY(m.s[1],i),getmaxx()/2,getmaxy()/2,0);
		m.s[2] = move3D(rotate3DY(m.s[2],i),getmaxx()/2,getmaxy()/2,0);

		m.t[0] = rotate3DY(m.t[0],i);
		m.t[1] = rotate3DY(m.t[1],i);
		m.t[2] = rotate3DY(m.t[2],i);
		m.t[3] = rotate3DY(m.t[3],i);
		m.draw();
		delay(10);
		cleardevice();
	}	
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);

	anim();



	getch();
	closegraph();
}

