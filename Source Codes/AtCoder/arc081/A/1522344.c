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
	return *(int*)b-*(int*)a;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int a[100000];
int t[2];
int main(void)
{
	int n,cnt=0,i;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),comp);
	FOR(i,0,n-1){
		if(a[i]==a[i+1]) t[cnt++]=a[i],i++;
		if(cnt==2) break;
	}
	if(cnt<2) puts("0");
	else printf("%lld\n",(ll)t[0]*t[1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:27:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&a[i]);
             ^