#include<stdio.h>

int gra[10][10];
int visited[10];
int N,M,ans;

int all_visited(){
	int a=1;
	for(int i=1;i<=N;i++)a*=visited[i];
	if(a>0)return 1;
	return 0;
}

void DFS(int v){
	if(all_visited()==1){
		ans++;
		return;
	}
	for(int i=1;i<=N;i++){
		if(gra[v][i]==1 && visited[i]==0){
			visited[i]=1;
			DFS(i);
			visited[i]=0;
		}
	}
	return;
}

int main(){
	scanf("%d%d",&N,&M);
	
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		gra[a][b]=gra[b][a]=1;
	}
	
	visited[1]=1;
	DFS(1);
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&M);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^