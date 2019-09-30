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
#define MOD 1000000007
#define SIZE 100005
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
char str[500010];
int a[500010];
int len;
int check(int k){
	int sum=0,i;
	FOR(i,0,len) a[i]=(str[len-i-1]-'0')*9;
	a[0]+=k;
	FOR(i,0,len+5){
		a[i+1]+=a[i]/10;
		sum+=a[i]%10;
		a[i]=0;
	}
	return sum<=k;
}
int main(void)
{
	int left,right,mid;
	scanf("%s",str);
	len=strlen(str);
	left=0,right=len*9+1;
	while(right-left>1){
		mid=(left+right)/2;
		if(check(mid)) right=mid;
		else left=mid;
	}
	printf("%d\n",(right+8)/9);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^