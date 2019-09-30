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
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int a[100000];
int main(void)
{
	int n,k,t,i;
	scanf("%d%d",&n,&k);
	FOR(i,0,n) scanf("%d",&a[i]);
	t=a[0];
	FOR(i,1,n) t=gcd(t,a[i]);
	FOR(i,0,n){
		if(a[i]>=k&&(a[i]-k)%t==0){
			puts("POSSIBLE");
			return 0;
		}
	}
	puts("IMPOSSIBLE");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:28:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&a[i]);
             ^