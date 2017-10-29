# include <iostream.h>
# include <graphics.h>
# include <conio.h>
# include <math.h>
# include <dos.h>

int initmouse();
void getmousepos(int *button, int *x, int *y);
void showmouseptr();
union REGS i,o ;

class Point {

	public:
		float x;
		float y;

		Point (int i = 0, int j = 0): x(i), y(j) {} ;
		Point operator+ (const Point& P) {return Point(this->x + P.x, this->y + P.y);}
		Point operator- (const Point& P) {return Point(this->x - P.x, this->y - P.y);}
		float operator* (const Point& P) {return this->x * P.x + this->y * P.y;}
		Point operator* (const float& S) {return Point(x*S, y*S);}
};


void clipper(Point point_arr[], int N, Point end_points[], Point normals[], float num[],
		float deno[], float t[] )
{

	/*Note:- uses normalized coordinate system*/
	Point P1 = end_points[0];
	Point P2 = end_points[1];

	Point diff_vec = P2-P1;
	int i = 0;

	// Normal calculations
	for (i = 0; i < N; ++i) {

		float x, y;
		if (i == N-1) {
			x = point_arr[0].x - point_arr[N-1].x;
			y = point_arr[0].y - point_arr[N-1].y;
		}
		else {
			x = point_arr[i+1].x - point_arr[i].x;
			y = point_arr[i+1].y - point_arr[i].y;
		}
		normals[i] = Point(y,-x);
	}

	// nums denos and ts
	for (i = 0; i < N; ++i) {
		num[i] = normals[i] * (P1 - point_arr[i]);
		deno[i] = normals[i] * diff_vec;
		t[i] = num[i]/(-1 * deno[i]);
	}
}

void cyrus_beck(Point point_arr[3], Point end_points[2], Point& inter1, Point& inter2, int N)
{
	Point normals[3];
	float num[3];
	float deno[3];
	float t[3];

	clipper(point_arr, N, end_points, normals, num, deno, t);
	float enter_max = 0;	// enter_max
	float exit_min  = 1;	// enter_min
	float t1, t2;
	for (int i=0; i < N; ++i) {
		if ((t[i] <= 1) && (t[i] >= 0)) {
			if (deno[i]>0)
				exit_min = (exit_min>t[i])?t[i]:exit_min;
			else
				enter_max = (enter_max<t[i])?t[i]:enter_max;
		}
	}
	t1 = exit_min, t2 = enter_max;
	inter1 = end_points[0] + (end_points[1] - end_points[0])*t1;
	inter2 = end_points[0] + (end_points[1] - end_points[0])*t2;

	return;
}

inline int inrange(int cx, int cy, int x, int y)
{
	int x_diff = abs(cx-x);
	int y_diff = abs(cy-y);

	return ((x_diff <= 5) && (y_diff <= 5));
}

int main()
{
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	int button, status, x, y;
	int pos;

	Point inter1, inter2;
	Point point_arr[3] = {Point(10,10), Point(100,40), Point(120, 100)};
	Point end_points[2] = {Point(20,80), Point(140,60)};
	int N = 3;

	cyrus_beck(point_arr, end_points, inter1, inter2, N);

	int polypoints[8] = {10,10,100,40,120,100,10,10};

	//setfillstyle(SOLID_FILL,WHITE);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,1,1);
	drawpoly(N+1,polypoints);

	setcolor(YELLOW);
	//line(end_points[0].x, end_points[0].y, end_points[1].x, end_points[1].y);
	circle(end_points[0].x, end_points[0].y, 5);
	circle(end_points[1].x, end_points[1].y, 5);
	//floodfill(end_points[1].x, end_points[1].y,YELLOW);
	//setcolor(RED);
	setcolor(CYAN);
	setlinestyle(SOLID_LINE,DOTTED_LINE,10);
	line(inter1.x, inter1.y, inter2.x, inter2.y);

	status = initmouse();

	if (!status)
		return 0;

	Point prev;
	int update = -1;
	while (!kbhit()) {
		//construct
		showmouseptr();

		setcolor(WHITE);
		setlinestyle(SOLID_LINE,1,1);
		drawpoly(N+1,polypoints);

		//setcolor(YELLOW);
		//line(end_points[0].x, end_points[0].y, inter1.x, inter1.y);
		//line(end_points[1].x, end_points[1].y, inter2.x, inter2.y);
		
		setcolor(YELLOW);
		circle(end_points[0].x, end_points[0].y, 5);
		circle(end_points[1].x, end_points[1].y, 5);

		setcolor(CYAN);
		setlinestyle(SOLID_LINE,DOTTED_LINE,10);
		line(inter1.x, inter1.y, inter2.x, inter2.y);


		getmousepos(&button, &x, &y);
		if (button == 1) {
			// left click
			button = 0;
			
			if (inrange(end_points[0].x, end_points[0].y, x, y))
				update = 0;
			else if (inrange(end_points[1].x, end_points[1].y, x, y))
				update = 1;
			else continue;

			//busy waiting
			while (button != 1) {
				getmousepos(&button, &x, &y);
				showmouseptr();
			}

			prev = end_points[update];
			end_points[update] = Point(x,y);
			//screen update
			cyrus_beck(point_arr, end_points, inter1, inter2, N);
			cleardevice();
		}
		
	}


	getch();
	closegraph();
	return 0;
}

int initmouse()
{
	i.x.ax = 0 ;
	int86(0X33 , &i , &o);
	return o.x.ax ;
}

void showmouseptr()
{
	i.x.ax = 1;
	int86(0X33 , &i , &o);
}

void getmousepos( int *button , int *x , int *y )
{
	i.x.ax = 3;
	int86(0X33 , &i , &o);

	*button = o.x.bx;
	*x = o.x.cx;
	*y = o.x.dx;
}