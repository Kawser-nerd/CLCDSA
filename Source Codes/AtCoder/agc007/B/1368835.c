#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define NUM 20001
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int b[20000];
int main(void)
{
	int n,p,i;
	scanf("%d",&n);
	FOR(i,0,n){
		printf("%d%c",NUM*(i+1),i==n-1?'\n':' ');
		b[i]=NUM*(n-i);
	}
	FOR(i,0,n){
		scanf("%d",&p);
		b[p-1]+=i;
	}
	FOR(i,0,n) printf("%d%c",b[i],i==n-1?'\n':' ');
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&p);
   ^