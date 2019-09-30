#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int bag[4][100];
int sum[4][101];
int size[4];
int w[100],v[100];
ll ws[4];
int main(void)
{
	int n,W,index,vsum,i,j,k,l;
	int w_0=INT_MAX,ans=0;
	ll s;
	scanf("%d%d",&n,&W);
	FOR(i,0,n){
		scanf("%d%d",&w[i],&v[i]);
		w_0=MIN(w_0,w[i]);
	}
	FOR(i,0,4) ws[i]=w_0+i;
	FOR(i,0,n){
		index=w[i]-w_0;
		bag[index][size[index]++]=v[i];
	}
	FOR(i,0,4){
		qsort(bag[i],size[i],sizeof(int),comp);
		sum[i][1]=bag[i][0];
		FOR(j,2,size[i]+1){
			sum[i][j]=sum[i][j-1]+bag[i][j-1];
		}
	}
	FOR(i,0,size[0]+1){
		FOR(j,0,size[1]+1){
			FOR(k,0,size[2]+1){
				FOR(l,0,size[3]+1){
					s=ws[0]*i+ws[1]*j+ws[2]*k+ws[3]*l;
					if(s<=W){
						vsum=sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l];
						ans=MAX(ans,vsum);
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&W);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&w[i],&v[i]);
   ^