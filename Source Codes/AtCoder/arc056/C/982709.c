#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))



typedef int DP;

int n,k;
int **w;

int bit_max;
int *s;
int i,j;
DP *dp;



void score(int i,int j,int h){
	int k,l;
	if(h == bit_max){
		return;
	}
	score(i,j+1,h << 1);
	s[i+h]=s[i];
	i += h;
	for(k=1,l=1;k<h;k=k<<1,l++){
		if(i & k){
			s[i] += w[j][l];
		}
	}
	score(i,j+1,h << 1);
}





int main(void){
	int i,j;

	scanf("%d%d",&n,&k);

	w = calloc(sizeof(int*),n+1);
	bit_max = 1 << n;
	s = calloc(sizeof(int),bit_max);
	dp = calloc(sizeof(DP),bit_max);
	for(i=1;i<=n;i++){
		w[i] = calloc(sizeof(int),n+1);
		for(j=1;j<=n;j++){
			scanf("%d",&w[i][j]);
		}
	}
	score(0,1,1);
	for(i=0;i<bit_max;i++){
		j = i;
		while(j != 0){
			dp[i] = max(dp[i],dp[j] + k - s[i] + s[j] + s[i^j]);
			j = (j-1)&i;
		}
	}
	printf("%d\n", dp[bit_max-1]);


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:57:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&w[i][j]);
    ^