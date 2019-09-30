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
ll gcd(ll a,ll b){
	return a%b==0?b:gcd(b,a%b);
}
int main(void)
{
	int t,i;
	ll a,b,c,d,g;
	scanf("%d\n",&t);
	while(t-->0){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(b>a) puts("No");
		else if(b>d) puts("No");
		else if(c>=b) puts("Yes");
		else{
			g=gcd(b,d);
			if(b-g+a%g>c) puts("No");
			else puts("Yes");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n",&t);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
   ^