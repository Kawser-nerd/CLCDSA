#include <stdio.h>

typedef long long ll;

ll dp[1<<16];
int bad[16][16];
 
int main() {

	int N,M;

	scanf("%d %d",&N,&M);

	int i,j,k;

	for(i=0;i<M;i++){
	int x,y;
	scanf("%d %d",&x,&y);
	x--;
	y--;
	bad[y][x]=1;
	}

	dp[0]=1ll;
	for(i=0;i<1<<N;i++){
		for(j=0;j<N;j++){
			if(!(i&(1<<j))){
			int ok=1;
			for(k=0;k<N;k++){
				if(i&(1<<k) &&bad[k][j]==1){ok=0;}//k?????j??????ok?k??????j?????end?????ok?
			}
			if(ok==1){
				dp[i+(1<<j)]+=dp[i];
				}
			}
		}
	}

	printf("%lld\n",dp[(1<<N)-1]);
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&x,&y);
  ^