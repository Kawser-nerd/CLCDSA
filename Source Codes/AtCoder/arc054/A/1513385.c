#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int main(void)
{
	int l,x,y,s,d,dist;
	double t1,t2;
	scanf("%d%d%d%d%d",&l,&x,&y,&s,&d);
	dist=s<d?d-s:l-s+d;
	t1=(double)dist/(x+y);
	t2=(double)(l-dist)/(y-x);
	printf("%.10lf\n",x<y?MIN(t1,t2):t1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d",&l,&x,&y,&s,&d);
  ^