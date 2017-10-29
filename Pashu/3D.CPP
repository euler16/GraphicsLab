#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

#define PI 3.14159

class Point
{
	public:
		float x;
		float y;
		float z;
		void anything(float first,float second,float third)
		{
			x=first;
			y=second;
			z=third;
		}
};

class Edge
{
	public:
		float x;
		float y;
		float z;
};

class Normal
{
	public:
		float x;
		float y;
		float z;
		void anything(Edge edge1,Edge edge2,int z)
		{
			
		}
}


Point general[4];
Point top[4];
Point front[4];
Point side[4];
Edge all_edges[6];
Normal all_normals[4];

void multimatrix(float A[10][10],float B[10][10],float C[10][10])
{
	int M=4;
	int N=4;
	int P=1;
	int i,j,k;
		for(i=0;i<M;i++)
		{
			for(j=0;j<P;j++)
			{
				for(k=0;k<N;k++)
				{
					C[i][j]+=A[i][k]*B[k][j];
				}
			}
		}
}

void draw(Point P[4])
{
	line(P[0].x,P[0].y,P[1].x,P[1].y);
	line(P[0].x,P[0].y,P[2].x,P[2].y);
	line(P[0].x,P[0].y,P[3].x,P[3].y);
	line(P[1].x,P[1].y,P[2].x,P[2].y);
	line(P[1].x,P[1].y,P[3].x,P[3].y);
	line(P[2].x,P[2].y,P[3].x,P[3].y);
}

void main()
{
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	int to_addy=120;
	int to_add_initial=107;
	int to_add=230;

	line(213,0,213,480);
	line(416,0,416,480);
	line(0,240,639,240);
	int i,j,k;

	//1,1,1
	//3,1,1
	//2,1,3
	//2,2,2

	general[0].anything(10,10,10);
	general[1].anything(30,10,10);
	general[2].anything(20,10,30);
	general[3].anything(20,20,20);

	k=0;
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			all_edges[k].x=general[i].x-general[j].x;
			all_edges[k].y=general[i].y-general[j].y;
			all_edges[k].z=general[i].z-general[j].z;
			++k;
		}
	}

	for(i=0;i<6;i++)
		cout<<all_edges[i].x<<" "<<all_edges[i].y<<" "<<all_edges[i].z<<endl;

	normal[0].set_normal(all_edges[1],all_edges[5],0);
	normal[1].set_normal(all_edges[3],all_edges[5],1);
	normal[2].set_normal(all_edges[0],all_edges[4],1);
	normal[3].set_normal(all_edges[0],all_edges[3],1);


	for(i=0;i<4;i++)
	{
		top[i].anything(general[i].x+to_add_initial,general[i].z+to_addy,0);
	}
	draw(top);

	for(i=0;i<4;i++)
	{
		front[i].anything(general[i].x+to_add_initial+to_add,general[i].y+to_addy,0);
	}
	draw(front);

	for(i=0;i<4;i++)
	{
		side[i].anything(general[i].y+to_add_initial+2*to_add,general[i].z+to_addy,0);
	}
	draw(side);

	getch();
}