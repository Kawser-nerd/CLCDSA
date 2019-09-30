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
int res[200];
int add[200];
int main(void)
{
	ll n;
	int m,size,s=0,i;
	scanf("%lld",&n);
	for(m=50;n<(1LL<<m)-1;m--);
	//printf("%d\n",1<<m);
	FOR(i,1,m+1) res[i-1]=i;
	n-=(1LL<<m)-1;
	size=m;
	for(i=m-1;i>=0;i--){
		if(n<(1LL<<i)) continue;
		m++;
		add[i]=m;
		n-=(1LL<<i);
	}
	printf("%d\n",m*2);
	FOR(i,0,size){
		if(add[i]) printf("%d ",add[i]);
		printf("%d ",res[i]);
	}
	FOR(i,0,m) printf("%d%c",i+1,i==m-1?'\n':' ');
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^