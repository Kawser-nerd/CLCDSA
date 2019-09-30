
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include 	<regex.h>
#include 	<math.h>
#define inf 1e40
#define err 0.000000000001
int c,d;
int info[201][2];
int A[201];
int cmp(void const *a,void const *b)
{return info[*(int *)a][0]-info[*(int *)b][0];}
double max(double a,double b)
{return a>b?a:b;}
int test(double x)
{
	int i,t,p;
	double left=info[A[0]][0]-x;
	for(i=0;i<c;i++)
	{
		t=info[A[i]][1];
		p=info[A[i]][0];
		while(t)
		{
			if(p+x<left)return 0;
			left=max(left,p-x)+d;
			t--;
		}
	}
	return 1;
}

double find(double l,double r)
{
	if(r-l<err)return (r+l)/2;
	double m=(l+r)/2;
	if(test(m))return find(l,m);
	else return find(m,r);
}
	int
main ( int argc, char *argv[] )
{
	int i,tc,j;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		scanf("%d%d",&c,&d);
		for(j=0;j<c;j++)
		{
			scanf("%d%d",&info[j][0],&info[j][1]);
			A[j]=j;
		}
		qsort(A,c,sizeof(A[0]),cmp);
//		for(j=0;j<c;j++)printf("%d ",info[A[j]][0]);
		
		printf("Case #%d: %.12f\n",i+1,find(0.0,inf));

	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
