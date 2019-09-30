#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int visited[50];
int graph[50][50];
int N;
void dfs(int v){
	visited[v] = 1;
	for(int v2=0;v2<N;v2++){
		if(graph[v][v2] == -1) continue;
		if(visited[v2] == 1)continue;
		dfs(v2);
	}
}

int main(void){
	int M,i,ans = 0;
	scanf("%d%d",&N,&M);
	int a[M],b[M];
	for(i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graph[i][j] = -1;
		}
	}
	for(i=0;i<M;i++){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--;
		b[i]--;
		graph[a[i]][b[i]] = 1;
		graph[b[i]][a[i]] = 1;
	}
	
	for(i=0;i<M;i++){
		graph[a[i]][b[i]] = -1;
		graph[b[i]][a[i]] = -1;
		for(int j=0;j<N;j++)visited[j] = -1;
		dfs(0);
		int bridge = -1;
		for(int j=0;j<N;j++){
			if(visited[j] == -1) bridge = 1;
		}
		if(bridge==1) ans++;
		graph[a[i]][b[i]] = 1;
		graph[b[i]][a[i]] = 1;
	}
	
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&M);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a[i],&b[i]);
   ^