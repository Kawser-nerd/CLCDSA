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

int n;
int map[60][60];
int from[60];
int pre[60];
int low[60];
int toutatu=1;
int bridge[60];
int dummy;

//bridge?1?????????from????????????
int search(int x){
	int i;

	if(pre[x]==0){
		pre[x]=toutatu;
		low[x]=toutatu;
		toutatu++;
	}

	fr(i,1,n+1){
		if(map[x][i]==1&&from[x]!=i){
			if(pre[i]>0){
				if(low[i]<low[x]){
					low[x]=low[i];
					search(from[x]);
				}
			}else{
				from[i]=x;
				dummy=search(i);
			}
		}
	}

	if(pre[x]==low[x]){
		bridge[x]=1;
	}else{
		bridge[x]=0;
	}

	return low[x];
}


int main(void)
{
	//?????
//	int n;
	int m;
	int a[1500];
	int b[1500];
//	int map[60][60];

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
	scanf("%d %d",&n,&m);
//	scanf_s("%d %d",&n,&m);

	fr(i,0,m){
		scanf("%d %d",&a[i],&b[i]);
//		scanf_s("%d %d",&a[i],&b[i]);	
	}

	fr(i,0,n+1){
		fr(j,0,n+1){
			map[i][j]=0;
		}
	}

	fr(i,0,m){
		map[a[i]][b[i]]=1;
		map[b[i]][a[i]]=1;
	}

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	search(1);
	bridge[1]=0;
	fr(i,0,n+1){
		ans=ans+bridge[i];
	}

	//	printf("??????\n");
	
	//??
	
	printf("%d",ans);
	
	fr(i,0,n+1){
		if(bridge[i]==1){
//			printf("(%d,%d)??",i,from[i]);
		}
	}

//	printf("pre[7]=%d,low[7]=%d",pre[7],low[7]);
	
	//	printf("???????\n");

	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:79:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:83:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a[i],&b[i]);
   ^