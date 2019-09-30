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
int map[500][500];
int res[500][500];
int main(void)
{
	int n,m,k,i,j;
	char c;
	scanf("%d%d%*c",&n,&m);
	FOR(i,0,n){
		FOR(j,0,m){
			scanf("%c",&c);
			map[i][j]=c-'0';
		}
		scanf("%*c");
	}
	FOR(i,1,n-1){
		res[i][1]=map[i][0],res[i][m-2]=map[i][m-1];
		res[i][0]=res[i][m-1]=0;
	}
	FOR(i,1,m-1){
		res[1][i]=map[0][i],res[n-2][i]=map[n-1][i];
		map[0][i]=map[n-1][i]=0;
	}
	k=MIN((n-3)/2,(m-3)/2);
	FOR(i,2,k+2){
		FOR(j,i,n-i){
			res[j][i]=map[j][i-1]-res[j][i-2]-res[j-1][i-1]-res[j+1][i-1];
			res[j][m-i-1]=map[j][m-i]-res[j][m-i+1]-res[j-1][m-i]-res[j+1][m-i];
		}
		FOR(j,i,m-i){
			res[i][j]=map[i-1][j]-res[i-2][j]-res[i-1][j-1]-res[i-1][j+1];
			res[n-i-1][j]=map[n-i][j]-res[n-i+1][j]-res[n-i][j-1]-res[n-i][j+1];
		}
	}
	FOR(i,0,n){
		FOR(j,0,m){
			printf("%d",res[i][j]);
		}
		puts("");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%*c",&n,&m);
  ^
./Main.c:29:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&c);
    ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%*c");
   ^