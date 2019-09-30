#include <stdio.h>

typedef long long ll;

int d[20][20];
ll dp[20][1<<20];

int main(){

	int N,M;

	scanf("%d %d",&N,&M);

	int i,j,mask;

	for(i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		d[a][b]=1;
		d[b][a]=1;
	}


	dp[0][1]=1;

	for(mask=0;mask<(1<<N);mask++){
		for(j=0;j<N;j++){
			if(!(mask>>j&1) ){
				int tmp=mask;
				for(i=0;i<N;i++){
					if(d[i][j]==1){
						dp[j][tmp|1<<j]+=dp[i][tmp];
					}
				}
			}
		}
	}

	ll ans=0ll;

	for(i=1;i<N;i++){
		ans+=dp[i][(1<<N)-1];
	}

	printf("%lld\n",ans);


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^