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
ll memo[20][2][2];
int L;
ll dfs(char str[],int a,int b,int c){
	int i;
	ll res=0;
	if(a==L) return b;
	if(memo[a][b][c]>=0) return memo[a][b][c];
	FOR(i,0,10){
		if(c&&i>str[a]-'0') break;
		res+=dfs(str,a+1,b||(i==4||i==9),c&&i==(str[a]-'0'));
	}
	return (memo[a][b][c]=res);
}
char str[20]; 
int main(void)
{
	int i;
	ll n1,n2;
	scanf("%s",str);
	L=strlen(str);
	for(i=L-1;i>=0;i--){
		if(str[i]=='0') str[i]='9';
		else{
			str[i]=str[i]-1;
			break;
		}
	}
	memset(memo,-1,sizeof(memo));
	n1=dfs(str,0,0,1);
	scanf("%s",str);
	L=strlen(str);
	memset(memo,-1,sizeof(memo));
	n2=dfs(str,0,0,1);
	printf("%lld\n",n2-n1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^