#include<stdio.h>

int N,M,R,ans=100000000;
int r[8];
int dist[200][200];
int visit[8];

int min(int a,int b){
	if(a<b)return a;
	return b;
}

void dfs(int c,int v,int dis){
	if(c==R)ans=min(ans,dis);
	for(int i=0;i<R;i++){
		if(visit[i]==0){
			visit[i]=1;
			dfs(c+1,i,dis+dist[r[v]][r[i]]);
			visit[i]=0;
		}
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&R);
	
	for(int i=0;i<R;i++){
		scanf("%d",&r[i]);
		r[i]--;
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)dist[i][j]=0;
			else dist[i][j]=100000000;
		}
	}
	
	for(int i=0;i<M;i++){
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		A--;
		B--;
		dist[A][B]=dist[B][A]=C;
	}
	
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
	
	for(int i=0;i<R;i++)dfs(0,i,0);
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&M,&R);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&r[i]);
   ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&C);
   ^