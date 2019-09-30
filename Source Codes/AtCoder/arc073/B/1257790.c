#include <stdio.h>
#include <stdlib.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}
void fill(int a[],int b,int c){
	for(int i=0;i<b;i++) a[i]=c;
	return;
}
int ary[4][100];
int item[4][101];
int s[4];
int main(void)
{
	int n,a,b,ans=0;
	int i,j,k,l;
	ll W,m;
	scanf("%d %lld",&n,&W);
	FOR(i,0,n){
		scanf("%d %d",&a,&b);
		if(!i) m=a;
		ary[a-m][s[a-m]++]=b;
	}
	FOR(i,0,4){
		qsort(ary[i],s[i],sizeof(int),comp);
		FOR(j,0,s[i]) item[i][j+1]=item[i][j]+ary[i][j];
	}
	FOR(i,0,s[0]+1){
		FOR(j,0,s[1]+1){
			FOR(k,0,s[2]+1){
				FOR(l,0,s[3]+1){
					if(m*i+(m+1)*j+(m+2)*k+(m+3)*l<=W){
						ans=MAX(ans,item[0][i]+item[1][j]+item[2][k]+item[3][l]);
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %lld",&n,&W);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^