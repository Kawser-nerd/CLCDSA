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
int ball[100000];
int flag[100000];
int main(void)
{
	int n,m,x,y,ans=0,i; 
	scanf("%d%d",&n,&m);
	FOR(i,0,n) ball[i]=1;
	flag[0]=1;
	FOR(i,0,m){
		scanf("%d%d",&x,&y);
		ball[--x]--,ball[--y]++;
		if(flag[x]) flag[y]=1;
		if(ball[x]==0) flag[x]=0;
	}
	FOR(i,0,n){
		if(ball[i]&&flag[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^