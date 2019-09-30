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
int d[7];
int main(void)
{
	int ans=0,k,i;
	FOR(i,0,7) scanf("%d",&d[i]);
	FOR(i,0,7){
		scanf("%d",&k);
		ans+=MAX(k,d[i]);
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,7) scanf("%d",&d[i]);
             ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^