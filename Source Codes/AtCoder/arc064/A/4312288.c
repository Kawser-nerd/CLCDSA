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
	ll int n,x;
	ll int a[100010];
	
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
	scanf("%lld %lld",&n,&x);
//	scanf_s("%lld %lld",&n,&x);

	fr(i,0,n){
		scanf("%lld",&a[i]);
//		scanf_s("%lld",&a[i]);
	}

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	fr(i,0,n){
		if(i==0){
			if(a[0]>x){
				ans=ans+a[0]-x;
				a[0]=x;
			}
		}else{
			if(a[i]+a[i-1]>x){
				ans=ans+a[i]+a[i-1]-x;
				a[i]=x-a[i-1];
			}
		}	
	}

	
	//	printf("??????\n");
	
	//??
	
	printf("%lld",ans);
	
	//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&x);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^