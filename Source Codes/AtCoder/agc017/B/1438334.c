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
	ll n,m,a,b,c,d;
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	FOR(m,0,n){
		if(c*(n-1-m)-d*m<=b-a&&b-a<=d*(n-1-m)-c*m){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
  ^