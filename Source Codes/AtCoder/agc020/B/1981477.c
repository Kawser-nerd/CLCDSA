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
#define INF 100000000
#define MOD 1000000007
#define SIZE 100005
#define LOCAL
#ifdef LOCAL
    #define DEBUG(...) printf(" "__VA_ARGS__)
#else
    #define DEBUG(...)
#endif /* LOCAL */
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
ll a[100000];
int main(void)
{
	int n,i;
	ll min,max;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%lld",a+i);
	if(a[n-1]!=2){
		puts("-1");
		return 0;
	}
	min=2,max=3;
	for(i=n-2;i>=0;i--){
		if(a[i]>max){
			puts("-1");
			return 0;
		}
		min=(min+a[i]-1)/a[i]*a[i];
		max=max/a[i]*a[i]+a[i]-1;
		if(min>max){
			puts("-1");
			return 0;
		}
	}
	printf("%lld %lld\n",min,max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:31:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%lld",a+i);
             ^