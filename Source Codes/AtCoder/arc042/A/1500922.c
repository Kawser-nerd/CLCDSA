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
int used[100001];
int main(void)
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	FOR(i,0,m) scanf("%d",&a[i]);
	for(i=m-1;i>=0;i--){
		if(!used[a[i]]){
			used[a[i]]=1;
			printf("%d\n",a[i]);
		}
	}
	FOR(i,1,n+1){
		if(!used[i]) printf("%d\n",i);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:26:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,m) scanf("%d",&a[i]);
             ^