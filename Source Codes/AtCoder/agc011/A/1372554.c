#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int a[100000];
int main(void)
{
	int n,c,k,cnt,res=0,t,i;
	scanf("%d%d%d",&n,&c,&k);
	FOR(i,0,n) scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),comp);
	for(i=0;;){
		t=a[i]+k;
		cnt=0,res++;
		while(i<n&&cnt<c&&a[i]<=t) i++,cnt++;
		if(i==n) break;
	}
	printf("%d\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&c,&k);
  ^
./Main.c:24:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&a[i]);
             ^