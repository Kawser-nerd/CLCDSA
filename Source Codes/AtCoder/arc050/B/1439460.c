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
int main(void)
{
	ll r,b,x,y;
	ll left=0,right=1e+18,mid;
	scanf("%lld%lld",&r,&b);
	scanf("%lld%lld",&x,&y);
	while(right-left>1){
		mid=(left+right)/2;
		if(r>=mid&&b>=mid&&(r-mid)/(x-1)+(b-mid)/(y-1)>=mid) left=mid;
		else right=mid;
	}
	printf("%lld\n",left);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&r,&b);
  ^
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&x,&y);
  ^