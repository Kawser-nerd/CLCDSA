#include <vector>
#include <algorithm>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <math.h>

FILE *Fin = fopen("C-large.in","r");
FILE *Fou = fopen("c.out","w");
//FILE *Fin = stdin;
//FILE *Fou = stdout;

#define MaxN 1100

int n,m,t;

struct Point
{
	int x,y,z,p;
} p[MaxN];

bool check(double d)
{
	int i,j,k;
	for (i=0; i<n; i++)
	{
		double min1=-1e10, min2=-1e10, max1=1e10, max2=1e10;

		for (j=0; j<n; j++)
		{
			double rem = d*p[j].p - abs(p[j].z-p[i].z);
			if (rem<0) break;
			min1 = max(min1, p[j].x+p[j].y-rem);
			max1 = min(max1, p[j].x+p[j].y+rem);
			min2 = max(min2, p[j].x-p[j].y-rem);
			max2 = min(max2, p[j].x-p[j].y+rem);
		}
		if (j==n)
		{
			if (max1-min1>1e-7 && max2-min2>1e-7) return true;
		}
	}
	return false;
}

int main()
{
	int i,j,k,caseN;
	fscanf(Fin,"%d",&caseN);
	for (int t=1; t<=caseN; t++)
	{
		fscanf(Fin,"%d",&n);
		for (i=0; i<n; i++)
			fscanf(Fin,"%d%d%d%d",&p[i].x,&p[i].y,&p[i].z,&p[i].p);
		double l = 0, r = 1e8;
		while (r-l>1e-7)
		{
			double mid = (l+r)/2;
			if (check(mid))
				r = mid;
			else
				l = mid;
		}

		fprintf(Fou,"Case #%d: %.6lf\n",t,(l+r)/2);
	}
	return 0;
}

