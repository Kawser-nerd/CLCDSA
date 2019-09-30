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
int used[SIZE];
int main(void)
{
	int n,i,res=0,s,a;
	scanf("%d",&n);
	FOR(i,0,n){
		scanf("%d",&a);
		used[a]++;
	}
	FOR(i,0,100000){
		s=used[i];
		if(i>0) s+=used[i-1];
		if(i<100000) s+=used[i+1];
		res=MAX(res,s);
	}
	printf("%d\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^