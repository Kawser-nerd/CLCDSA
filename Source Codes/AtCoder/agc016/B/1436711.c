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
int a[100000];
int main(void)
{
	int n,min=INF,max=0,cnt=0,i;
	scanf("%d",&n);
	FOR(i,0,n){
		scanf("%d",&a[i]);
		min=MIN(min,a[i]);
		max=MAX(max,a[i]);
	}
	if(max-min>1) puts("No");
	else if(max==min){
		if(max==n-1) puts("Yes");
		else if(max<=n/2) puts("Yes");
		else puts("No");
	}else{
		FOR(i,0,n) if(a[i]==min) cnt++;
		if(cnt==n-1) puts("No");
		else if(max>cnt&&max<=(n-cnt)/2+cnt) puts("Yes");
		else puts("No");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^