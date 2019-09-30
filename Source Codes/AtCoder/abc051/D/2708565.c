#include <stdio.h>

int cost[105][105];
int used[105];
int d[105][105];

int N,M;
int a[1005];
int b[1005];
int c[1005];

void warshall_floyd(){

	int i,j,k;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			d[i][j]=cost[i][j];
		}
	}

	for(k=0;k<N;k++){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}

}

int main(){

	scanf("%d %d",&N,&M);

	int i,j;
	for(i=0;i<M;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		cost[a[i]-1][b[i]-1]=c[i];
		cost[b[i]-1][a[i]-1]=c[i];
	}

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j){cost[i][j]=0;}
			else{
				if(cost[i][j]==0){cost[i][j]=1<<20;}
			}
		}
	}

	warshall_floyd();

	int ans=0;

	for(i=0;i<M;i++){
		if(c[i]>d[a[i]-1][b[i]-1]){
		ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a[i],&b[i],&c[i]);
   ^