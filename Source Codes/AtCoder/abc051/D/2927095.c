#include <stdio.h>

int a[1005];
int b[1005];
int c[1005];
int dist[105][105];

int min(int x,int y){
	if(x<y){return x;}
	else{return y;}
}

int main(){

	int N,M;

	scanf("%d %d",&N,&M);

	int i,j,k;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j){dist[i][j]=0;}
			else{dist[i][j]=1<<25;}
		}
	}

	for(i=0;i<M;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		a[i]--;
		b[i]--;
		dist[a[i]][b[i]]=c[i];
		dist[b[i]][a[i]]=c[i];
	}

	for(k=0;k<N;k++){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	int ans=0;
	for(i=0;i<M;i++){
		if(dist[a[i]][b[i]]<c[i]){ans++;}
	}
	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a[i],&b[i],&c[i]);
   ^