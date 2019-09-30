//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//#include <set>
//#include <map>
//#include <iostream>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12


int main(void)
{
	//?????
	int n,m;

	//??????
	int i,j,l;
	int flag=0;
	ll int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;


	//????????
	scanf("%d %d",&n,&m);
//	scanf_s("%d %d",&n,&m);

/*	fri(m){
		scanf("%d",x[i]);
		scanf_s("%d",&x[i]);
	}
*/

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????

	if(n==m){
		ans=2;
	}else if(abs(n-m)==1){
		ans=1;
	}else{
		printf("0");
		return 0;
	}

	for(i=1;i<=n;i++){
		ans=ans*i;
		ans=ans%1000000007;
	}

	for(i=1;i<=m;i++){
		ans=ans*i;
		ans=ans%1000000007;
	}

	//	printf("??????\n");

	//??

	printf("%lld",ans);

	//	printf("???????\n");


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^