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
char str[200001];
int cnt[26];
int main(void)
{
	ll ans;
	int len,i;
	scanf("%s",str);
	len=strlen(str);
	FOR(i,0,len) cnt[str[i]-'a']++;
	ans=(ll)len*(len-1)/2+1;
	FOR(i,0,26) ans-=(ll)cnt[i]*(cnt[i]-1)/2;
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^