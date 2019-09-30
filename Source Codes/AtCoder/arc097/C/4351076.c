//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//#include <vector>
//#include <set>
//#include <map>
//#include <iostream>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define swap(p,q) r=(p);(p)=(q);(q)=r
#define INF 1000000000000//10^12

int n;
int white[2010][2010];
int black[2010][2010];
int dp[2010][2010];

void init(int n){
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			dp[i][j]=-1;
		}
	}
}

int search(int w,int b){
	int s,t;

	if(dp[w][b]!=-1) return dp[w][b];
	if(w==n&&b==n){
		return 0;
	}else if(w==n){
		dp[w][b]=search(w,b+1)+black[b+1][w];
	}else if(b==n){
		dp[w][b]=search(w+1,b)+white[w+1][b];
	}else{
		s=search(w+1,b)+white[w+1][b];
		t=search(w,b+1)+black[b+1][w];
	
		dp[w][b]=min(s,t);
	}
	return dp[w][b];
}

int main(void)
{
	//?????
//	int n;
	char color;
	int c[4010];
	int a[4010];
	int w[2010];
	int b[2010];
	int r;

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

	for(i=0;i<2*n;i++){
		scanf("\n%c %d",&color,&a[i]);
//		scanf_s("\n");
//		scanf_s("%c",&color);
//		scanf_s("%d",&a[i]);
		if(color=='W'){
			c[i]=0;
			w[a[i]]=i;
		}else{
			c[i]=1;
			b[a[i]]=i;
		}
	}

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????

	for(i=1;i<=n;i++){
		white[i][0]=w[i];
		black[i][0]=b[i];
	}

	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			if(w[j]<w[i]) white[i][0]--;
			if(b[j]<b[i]) black[i][0]--;
		}
	}

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(b[j]<w[i]){
				white[i][j]=white[i][j-1]-1;
			}else{
				white[i][j]=white[i][j-1];
			}

			if(w[j]<b[i]){
				black[i][j]=black[i][j-1]-1;
			}else{
				black[i][j]=black[i][j-1];
			}
		}
	}

/*	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			printf("black[%d][%d]=%d\n",i,j,black[i][j]);
		}
		for(j=0;j<=n;j++){
			printf("white[%d][%d]=%d\n",i,j,white[i][j]);
		}
	}*/

	init(n);
	ans=search(0,0);

/*	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	*/
	//	printf("??????\n");

	//??

	printf("%d",ans);

	//	printf("???????\n");


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:78:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:82:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("\n%c %d",&color,&a[i]);
   ^