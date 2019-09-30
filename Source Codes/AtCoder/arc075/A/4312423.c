//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ll long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12




int main(void)
{
	//?????
	int n;
	int s[110];
	static int dp[100][10010];
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	
	
	//????????
	scanf("%d",&n);
//	scanf_s("%d",&n);

	fr(i,0,n){
		scanf("%d",&s[i]);
//		scanf_s("%d",&s[i]);
	}

	fr(i,0,n){
		fr(j,0,10010){
			dp[i][j]=0;
		}
	}

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	dp[0][0]=1;
	dp[0][s[0]]=1;

	fr(i,1,n){
		fr(j,0,10010){
			if(j>=s[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-s[i]]);
			if(j<s[i])  dp[i][j]=dp[i-1][j];
		}
	}

	for(i=10000;i>0;i--){
		if(i%10!=0&&dp[n-1][i]!=0){
			ans=i;
			break;
		}
	}

	//	printf("??????\n");
	
	//??
	
	printf("%d",ans);
	
	//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s[i]);
   ^