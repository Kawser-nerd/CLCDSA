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
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int grid[2001][2001];
int a[2001][2001];
int b[2001][2001];
int c[2001][2001];
int main(void)
{
	int n,m,q,x1,x2,y1,y2,s1,s2,s3,i,j;
	char t;
	scanf("%d%d%d%*c",&n,&m,&q);
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			scanf("%c",&t);
			grid[i][j]=t-'0';
		}
		scanf("%*c");
	}
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			a[i][j]=grid[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			b[i][j]=(grid[i][j]==1&&grid[i][j-1]==1)+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
			c[i][j]=(grid[i][j]==1&&grid[i-1][j]==1)+c[i-1][j]+c[i][j-1]-c[i-1][j-1];
		}
	}
	FOR(i,0,q){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		s1=a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
		s2=b[x2][y2]-b[x1-1][y2]-b[x2][y1]+b[x1-1][y1];
		s3=c[x2][y2]-c[x1][y2]-c[x2][y1-1]+c[x1][y1-1];
		printf("%d\n",s1-s2-s3);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%*c",&n,&m,&q);
  ^
./Main.c:31:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&t);
    ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%*c");
   ^
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
   ^