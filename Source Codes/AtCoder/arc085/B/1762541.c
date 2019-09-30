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
#define MOD 1000000007
#define SIZE 100005
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
int a[2000];
int main(void)
{
	int z,w,n,max,min,i;
	scanf("%d%d%d",&n,&z,&w);
	FOR(i,0,n) scanf("%d",a+i);
	if(n==1) printf("%d\n",abs(a[0]-w));
	else if(abs(a[n-2]-a[n-1])>abs(a[n-1]-w)) printf("%d\n",abs(a[n-2]-a[n-1]));
	else printf("%d\n",abs(a[n-1]-w));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&z,&w);
  ^
./Main.c:23:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",a+i);
             ^