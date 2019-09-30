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


int search(int a,int b,int kaisu){
	if(a==b){
		return kaisu;
	}else if(a==-b){
		return kaisu+1;
	}else if(a<-abs(b)){
		return search(-abs(b),b,kaisu-abs(b)-a);
	}else if(a>abs(b)){
		return search(-a,b,kaisu+1);
	}else if(a>=0){
		return search(abs(b),b,kaisu+abs(b)-a);
	}else{
		return search(-a,b,kaisu+1);
	}
}


int main(void)
{
	//?????
	int x,y;

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
	scanf("%d %d",&x,&y);
//	scanf_s("%d %d",&x,&y);

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	ans=search(x,y,0);

	//	printf("??????\n");
	
	//??
	
	printf("%d",ans);

	//	printf("???????\n");

	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&x,&y);
  ^