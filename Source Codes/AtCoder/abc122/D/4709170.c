#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
int dp[101][6][6][6][6];//
int N;
//1=A,2=C,3=G,4=T


int cnt(int num,int a,int b,int c,int d){
	if(dp[num][a][b][c][d] != -1) return dp[num][a][b][c][d];
	if(a == 1&& c == 3&& d == 2)return 0;
	if(a == 1&& b == 3&& d == 2)return 0;
	if(b == 1&& c == 3&& d == 2)return 0;
	if(b == 1&& c == 2&& d == 3)return 0;
	if(b == 3&& c == 1&& d == 2)return 0;
	if(num == N) return 1;

	long ans = 0;
	for(int i = 1; i < 5; i++) ans += cnt(num+1,b,c,d,i);
	return dp[num][a][b][c][d]=ans%MOD;

}

int main(){
	if(scanf("%d",&N)==1){
		memset(dp,-1,sizeof(dp));
		printf("%d\n",cnt(0,5,5,5,5));
	}else{
		printf("ERROR\n");
	}

	return 0;
}