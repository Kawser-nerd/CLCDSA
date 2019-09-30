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
	ll int n;

	//??????
	int i,j,l;
	int flag=0;
	ll int ans=0;
	int count=0;
	ll int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;


	//????????
	scanf("%lld",&n);
//	scanf_s("%lld",&n);

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????

	ans=100;

	for(i=1;i<sqrt(n)+1;i++){
		if(n%i==0){
			count=0;
			temp=n/i;
			while(temp!=0){
				temp=temp/10;
				count++;
			}
			ans=min(ans,count);
		}
	}


	//	printf("??????\n");

	//??

	printf("%lld",ans);

	//	printf("???????\n");


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^