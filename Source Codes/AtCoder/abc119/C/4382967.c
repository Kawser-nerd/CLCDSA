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

//using namespace std;


int main(void)
{
	//?????
	int n,a,b,c;
	int l[10];
	int cost;
	int sum[2][500];

	//??????
	int i,j,k;
	int flag=0;
	int ans=0;
	int cnt=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	//int sum=0;



	//????????


	scanf("%d %d %d %d",&n,&a,&b,&c);
//	scanf_s("%d %d %d %d",&n,&a,&b,&c);

	for(i=0;i<n;i++){
		scanf("%d",&l[i]);
//		scanf_s("%d",&l[i]);
	}


	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	for(i=0;i<(1<<n);i++){
		len=0;
		cost=0;
		for(j=0;j<n;j++){
			if(i&(1<<j)){
				if(len==0){
					len=l[j];
				}else{
					len=len+l[j];
					cost=cost+10;
				}
			}
		}

		sum[0][i]=len;
		sum[1][i]=cost;

	}

	ans=10000;
	for(i=1;i<(1<<n);i++){
		for(j=1;j<(1<<n);j++){
			for(k=1;k<(1<<n);k++){
				if((i&j)==0&&((j&k)==0&&(k&i)==0)){
//					printf("i=%d,j=%d,k=%d,i&j&k=%d\n",i,j,k,i&(j&k));
					temp=abs(a-sum[0][i])+abs(b-sum[0][j])+abs(c-sum[0][k])+sum[1][i]+sum[1][j]+sum[1][k];
					ans=min(ans,temp);
				}
			}
		}
	}

	//	printf("??????\n");

	//??

	printf("%d",ans);

	//	printf("???????\n");


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&n,&a,&b,&c);
  ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&l[i]);
   ^