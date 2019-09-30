#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define infile "a.in"

FILE *fin=fopen(infile,"r"),
	*fout=fopen("a.out","w");

const int maxn = 1010;

struct Twire{
	int x,y;
}wire[maxn+1];

int n;


bool jiao(int x1,int y1, int x2, int y2)
{
	if ((x1<x2)&&(y1>y2))
		return true;
	if ((x1>x2)&&(y1<y2))
		return true;
	return false;
}

int main()
{
	int t,w,i,j, result;
	fscanf(fin,"%d",&t);
	for (w=1; w<=t; ++w)
	{
		fscanf(fin,"%d",&n);
		result=0;
		for (i=1; i<=n; ++i)
		{
			fscanf(fin,"%d%d",&wire[i].x,&wire[i].y);
		}

		for (i=1; i<=n; ++i)
			for (j=i+1; j<=n; ++j)
				if (jiao(wire[i].x,wire[i].y,wire[j].x,wire[j].y))
					++result;		

		fprintf(fout,"Case #%d: %d\n", w, result);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}