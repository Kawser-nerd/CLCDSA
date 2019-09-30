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
	ll int n,q,h,s,d;
	
	//??????
	int i,j,k,l;
	int flag=0;
	ll int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	
	
	//????????
	scanf("%lld %lld %lld %lld %lld",&q,&h,&s,&d,&n);
//	scanf_s("%lld %lld %lld %lld %lld",&q,&h,&s,&d,&n);



	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	s=min(q*4,min(h*2,s));

	if(d<2*s){
		ans=n/2*d+n%2*s;
	}else{
		ans=n*s;
	}

	//	printf("??????\n");
	
	//??
	
	printf("%lld",ans);
	
	//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld %lld %lld",&q,&h,&s,&d,&n);
  ^