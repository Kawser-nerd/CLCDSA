#include <stdio.h>
int g[9][9]={0};
int visit[9]={0},n;

int DFS(int now){
	visit[now]=1; //now??????
	int flag=1,cnt=0;
	for(int i=1;i<=n;i++) flag*=visit[i];
	if(flag){//?????????1???
		visit[now]=0;
		return 1;
	}
	//???????
	for(int i=2;i<=n;i++)if(g[now][i]==1 && visit[i]==0) cnt+=DFS(i);//???????????DFS
	visit[now]=0;//now????????
	return cnt;
}

int main(void){
	int m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		g[a][b]=1;
		g[b][a]=1;
	}
	
	printf("%d",DFS(1));//??1????????
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^