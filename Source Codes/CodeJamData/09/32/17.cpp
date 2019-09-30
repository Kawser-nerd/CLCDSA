#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)<(b)?(b):(a))
#define INF INF32
#define NA (-1)

#define uint64 unsigned __int64
#define _1 ((uint64)1)
#define int64 __int64

const int64 INF64=(_1<<63)-1;
const int INF32=(_1<<31)-1;

using namespace std;

FILE *fin=fopen("B-large.in","r");
FILE *fout=fopen("B-large.out","w");

#define MAXN 10011

double x,y,z,vx,vy,vz;

void init()
{
	int n,i;
	double tx,ty,tz,tvx,tvy,tvz;

	x=0;
	y=0;
	z=0;
	vx=0;
	vy=0;
	vz=0;
	fscanf(fin,"%d",&n);
	for (i=0; i<n; i++)
	{
		fscanf(fin,"%lf %lf %lf %lf %lf %lf",&tx,&ty,&tz,&tvx,&tvy,&tvz);
		x+=tx;
		y+=ty;
		z+=tz;
		vx+=tvx;
		vy+=tvy;
		vz+=tvz;
	}
	x/=n;
	y/=n;
	z/=n;
	vx/=n;
	vy/=n;
	vz/=n;
}

double dist(double t)
{
	return sqrt((x+t*vx)*(x+t*vx)+(y+t*vy)*(y+t*vy)+(z+t*vz)*(z+t*vz));
}

void search()
{

	if (vx*vx+vy*vy+vz*vz==0)
	{
		fprintf(fout,"%0.8lf %0.8lf\n",dist(0),0);
		return;
	}

	double t=-(vx*x+vy*y+vz*z)/(vx*vx+vy*vy+vz*vz);

	if (t<=0)
		fprintf(fout,"%0.8lf %0.8lf\n",dist(0),0);
	else
		fprintf(fout,"%0.8lf %0.8lf\n",dist(t),t);
}

int main()
{
	int testdata,i;

	fscanf(fin,"%d",&testdata);
	for (i=0; i<testdata; i++)
	{
		fprintf(fout,"Case #%d: ",i+1);
		init();
		search();
	}
	return 0;
}
