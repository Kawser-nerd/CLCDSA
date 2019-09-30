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


	scanf("%d %d %d %d",&a,&b,&c,&k);
//	scanf_s("%d %d %d %d",&a,&b,&c,&k);

/*	for(i=0;i<n;i++){
		scanf("%d",&l[i]);
		scanf_s("%d",&l[i]);
	}
	*/

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	if(k%2==0){
		ans=a-b;
	}else{
		ans=b-a;
	}

	//	printf("??????\n");

	//??

	printf("%d",ans);

	//	printf("???????\n");


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&a,&b,&c,&k);
  ^