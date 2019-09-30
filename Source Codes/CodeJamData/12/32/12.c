#include<stdio.h>
#include<math.h>
int T;
struct am{
double t;
double d;
};
main()
{
FILE *fin  = fopen ("ae.in", "r");
FILE *fout = fopen ("ac.out", "w");
long int i,j,k,N,A;
double D,a[10],tt,tm,v;
struct am ar[2];
fscanf(fin,"%ld\n",&T);
for(i=0;i<T;i++)
	{
	fscanf(fin,"%lf",&D);
	fscanf(fin,"%ld %ld\n",&N,&A);
	for(j=0;j<N;j++)
		{
		fscanf(fin,"%lf %lf\n",&ar[j].t,&ar[j].d);
		}
	for(j=0;j<A;j++)
	fscanf(fin,"%lf",&a[j]);
	fprintf(fout,"Case #%ld:\n",i+1);
	if(N==2)
	{v=(ar[1].t-ar[0].t);
	v/=(ar[1].d-ar[0].d);
	tm=(D-ar[0].d)*v;
	for(j=0;j<A;j++)
		{
		tt=2*D/a[j];
		tt=sqrt(tt);
		if(tt>tm)
		fprintf(fout,"%lf\n",tt);
		else
		fprintf(fout,"%lf\n",tm);
		}
	}
	else
	for(j=0;j<A;j++)
		{
		tt=2*D/a[j];
		tt=sqrt(tt);
		fprintf(fout,"%lf\n",tt);
		}
	}
return 0;
}
