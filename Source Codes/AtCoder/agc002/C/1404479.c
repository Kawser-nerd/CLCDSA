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
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int a[100000];
int main(void)
{
	int n,l,max=0,num,i;
	scanf("%d%d",&n,&l);
	FOR(i,0,n) scanf("%d",&a[i]);
	FOR(i,0,n-1){
		if(a[i]+a[i+1]>max){
			max=a[i]+a[i+1];
			num=i+1;
		}
	}
	if(max<l) puts("Impossible");
	else{
		puts("Possible");
		FOR(i,1,num) printf("%d\n",i);
		FOR(i,1,n-num+1) printf("%d\n",n-i);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&l);
  ^
./Main.c:22:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&a[i]);
             ^