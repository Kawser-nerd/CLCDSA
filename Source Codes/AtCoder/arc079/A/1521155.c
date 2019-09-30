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
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int p[200000],q[200000];
int main(void)
{
	int n,m,a,b,i;
	scanf("%d%d",&n,&m);
	FOR(i,0,m){
		scanf("%d%d",&a,&b);
		if(a>b) swap(int,a,b);
		if(a==1) p[b-1]=1;
		if(b==n) q[a-1]=1;
	}
	FOR(i,1,n-1){
		if(p[i]&&q[i]){
			puts("POSSIBLE");
			return 0;
		}
	}
	puts("IMPOSSIBLE");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^