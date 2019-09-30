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
char map[2][53];
int main(void)
{
	int n,flag,i;
	const ll MOD=(1e+9)+7;
	ll ans;
	scanf("%d",&n);
	FOR(i,0,2) scanf("%s",map[i]);
	FOR(i,0,n){
		if(i!=n-1&&map[0][i]==map[0][i+1]){
			if(i==0) ans=6;
			else if(flag) ans=ans*3%MOD;
			else ans=ans*2%MOD;
			flag=1;
		}
		if(map[0][i]==map[1][i]){
			if(i==0) ans=3;
			else if(!flag) ans=ans*2%MOD; 
			flag=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:28:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,2) scanf("%s",map[i]);
             ^