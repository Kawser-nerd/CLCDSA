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
	int a[100010];

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

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
//		scanf_s("%d",&a[i]);
	}

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	temp=0;
	ans=1;
	for(i=1;i<n;i++){
		if(temp==0){
			if(a[i]>a[i-1]){
				temp=1;
			}else if(a[i]<a[i-1]){
				temp=-1;
			}
		}else if(a[i]>a[i-1]&&temp==-1){
			ans++;
			temp=0;
		}else if(a[i]<a[i-1]&&temp==1){
			ans++;
			temp=0;
		}
	}

	//	printf("??????\n");
	
	//??
	
	printf("%d",ans);

	//	printf("???????\n");

	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^