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
int s[100000],t[100000];
int a[300002];
int sec[300001];
int res[100000];
int main(void)
{
	int n,m,size=0,i; 
	scanf("%d%d",&n,&m);
	FOR(i,0,m){
		scanf("%d%d",&s[i],&t[i]);
		a[s[i]]++,a[t[i]+1]--;
	}
	FOR(i,2,n+1) a[i]+=a[i-1];
	FOR(i,1,n+1) sec[i]=(a[i]>1);
	FOR(i,2,n+1) sec[i]+=sec[i-1];
	FOR(i,0,m){
		if(sec[t[i]]-sec[s[i]-1]==t[i]-s[i]+1){
			res[size++]=i+1;
		}
	}
	printf("%d\n",size);
	FOR(i,0,size) printf("%d\n",res[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&s[i],&t[i]);
   ^