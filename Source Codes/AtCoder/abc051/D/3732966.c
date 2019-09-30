#include<stdio.h>

int N,M,ans;
int gra[101][101];
int pgra[101][101];
int used[101][101];

int min(int x,int y){
	if(x<y)return x;
	return y;
}

void search(int start,int goal){
	int i;
	int cur;
	cur=start;
	/*while(cur!=goal){
		for(i=1;i<=N;i++)
			if((i!=cur) && (pgra[cur][i]+gra[i][goal]==gra[cur][goal])){
				if(used[cur][i]==0)ans--;
				used[cur][i]=1;
				used[i][cur]=1;
				cur=i;
				break;
			}
	}*/
	for(i=1;i<=N;i++)
		if((i!=cur) && (pgra[cur][i]+gra[i][goal]==gra[cur][goal])){
			if(used[cur][i]==0)ans--;
			used[cur][i]=1;
			used[i][cur]=1;
			search(i,goal);
		}
}

int main(){
	
	scanf("%d%d",&N,&M);
	ans=M;
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)if(i!=j)gra[i][j]=9999999;
	
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		gra[a][b]=gra[b][a]=c;
	}
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)pgra[i][j]=gra[i][j];
	
	
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++){
				gra[i][j]=min(gra[i][j],gra[i][k]+gra[k][j]);
			}
	
	for(int i=1;i<N;i++)
		for(int j=i+1;j<=N;j++)search(i,j);
			
	printf("%d\n",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&M);
  ^
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^