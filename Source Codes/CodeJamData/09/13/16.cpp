#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define infile "a3.in"
#define outfile "a3.out"

FILE *fin=fopen(infile,"r"),
	*fout=fopen(outfile,"w");

double f[41],result;
long c,n;

double calc(long i,long k)
{
	double result;
	long w,now;
	if (i<n-k)
		return 0;
	if (c-i<k)
		return 0;
	result=1;
	now=c;
	for (w=1; w<=n-k; ++w)
	{
		result=result*(i-w+1.0)/(now+0.0);
		--now;
	}
	for (w=1; w<=k; ++w)
	{
		result=result*(c-i-w+1.0)/(now+0.0);
		--now;
	}
	for (w=1; w<=k; ++w)
		result=result*(n-w+1.0)/(k-w+1.0);
	return result;
}

void init()
{
	fscanf(fin,"%ld%ld",&c,&n);
}

void work()
{
	long i,j,k;
	double bd,xs;
	f[c]=0;
	for (i=c-1; i>=0; --i)
	{	
		bd=calc(i,0);
		xs=0;
		for (k=1; k<=n; ++k)
		{
			xs+=calc(i,k)*(f[i+k]+1.0);
		}
		f[i]=(xs+bd)/(1-bd);
	}
	result=f[0];
}

void output()
{
	
}

int main()
{
	long w,t;
	fscanf(fin,"%ld",&t);
	for (w=1; w<=t; ++w)
	{
		init();
		work();
		fprintf(fout,"Case #%ld: %.7lf\n", w, result);
//		output();	
	}
	fclose(fin);
	fclose(fout);
	return 0;
}