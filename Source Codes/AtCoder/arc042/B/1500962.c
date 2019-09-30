#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int x[10],y[10];
int main(void)
{
	int nx,ny,n,i;
	double t,k,res;
	scanf("%d%d",&nx,&ny);
	scanf("%d",&n);
	FOR(i,0,n){
		scanf("%d%d",&x[i],&y[i]);
	}
	t=(double)(y[0]-y[n-1])/(x[0]-x[n-1]);
	res=(fabs(t*nx-ny-t*x[0]+y[0]))/(sqrt(t*t+1));
	FOR(i,0,n-1){
		t=(double)(y[i+1]-y[i])/(x[i+1]-x[i]);
		k=(fabs(t*nx-ny-t*x[i]+y[i]))/(sqrt(t*t+1));
		res=MIN(res,k);
	}
	printf("%.10lf\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&nx,&ny);
  ^
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x[i],&y[i]);
   ^