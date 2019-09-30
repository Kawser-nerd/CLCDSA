#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#define FOR(i,a,n) for(i=(a);i<(n);i++)
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 1000000000
#define MOD 1000000007
#define SIZE 100005
//#define LOCAL
#ifdef LOCAL
    #define DEBUG(...) printf(" "__VA_ARGS__)
#else
    #define DEBUG(...)
#endif /* LOCAL */
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
int x[1000],y[1000],c[1000];
int n;
int check(double t){
	int i;
	double max_x,min_x,max_y,min_y;
	max_x=max_y=INF;
	min_x=min_y=-INF;
	FOR(i,0,n){
		max_x=MIN(max_x,x[i]+t/c[i]);
		max_y=MIN(max_y,y[i]+t/c[i]);
		min_x=MAX(min_x,x[i]-t/c[i]);
		min_y=MAX(min_y,y[i]-t/c[i]);
	}
	DEBUG("%lf %lf\n %lf %lf\n",max_x,min_x,max_y,min_y);
	return (max_x>=min_x&&max_y>=min_y);
}
int main(void)
{
	int i;
	double left,right,mid;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d%d%d",x+i,y+i,c+i);
	left=0,right=INF;
	
	FOR(i,0,100){
		mid=(left+right)/2;
		if(check(mid)) right=mid;
		else left=mid;
	}

	printf("%.12lf\n",right);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:46:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d%d%d",x+i,y+i,c+i);
             ^