#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000
int N,M,R,ans;
int r[9];
int visited[9]={0};
int d[201][201]={0};

int min(int x,int y){return x<y?x:y;}

void dfs(int n,int last,int dist){
	if(n==R+1){
		ans = min(ans,dist);
		return;
	}
	for(int i=1;i<=R;i++){
		if(visited[i]==0){
			visited[i]=1;
			if(last==-1)dfs(n+1,i,0);
			else dfs(n+1,i,dist+d[r[last]][r[i]]);
			visited[i]=0;
		}
	}
}

int main(void){
	scanf("%d%d%d",&N,&M,&R);
	for(int i=1;i<=R;i++)scanf("%d",&r[i]);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(j!=i)d[i][j] = INF;
		}
	}
	for(int i=1;i<=M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(d[a][b]>c)d[a][b] = d[b][a] = c;
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				d[i][j] = min(d[i][k]+d[k][j],d[i][j]);
			}
		}
	}
	ans = INF;
	dfs(1,-1,0);
	printf("%d",ans);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&M,&R);
  ^
./Main.c:28:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=1;i<=R;i++)scanf("%d",&r[i]);
                       ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^