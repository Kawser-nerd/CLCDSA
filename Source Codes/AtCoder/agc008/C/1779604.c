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
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
ll a[7];
int main(void)
{
	int i;
	ll n1,n2;
	FOR(i,0,7) scanf("%lld",a+i);
	n1=n2=a[1];
	if(a[0]>0&&a[3]>0&&a[4]>0) n1+=(a[0]-1)/2*2+(a[3]-1)/2*2+(a[4]-1)/2*2+3;
	n2+=a[0]/2*2+a[3]/2*2+a[4]/2*2;
	printf("%lld\n",MAX(n1,n2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,7) scanf("%lld",a+i);
             ^