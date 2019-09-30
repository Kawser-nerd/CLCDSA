#include<stdio.h>

int main(){
		int n,m,i,ab[30][2],ans=0,ttyk[10][10]={0},j;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
				scanf("%d%d",&ab[i][0],&ab[i][1]);
				ttyk[ab[i][0]][ab[i][1]]=1;
				ttyk[ab[i][1]][ab[i][0]]=1;
		}
		int dfs[100000][10]={0},st=0,fn=1;
		dfs[0][0]=1;
		dfs[0][1]=1;
		while(fn>st){
				int f=0;
				for(j=1;j<=n;j++){
						if(ttyk[dfs[st][0]][j]==1&&dfs[st][j]!=1){
								dfs[fn][0]=j;
								for(i=1;i<=n;i++)dfs[fn][i]=dfs[st][i];
								dfs[fn][j]=1;
								fn++;
								f=1;
						}
				}
				if(f==0){
						for(j=1;j<=n;j++){
								if(dfs[st][j]==0)break;
						}
						if(j==n+1)ans++;
				}
				st++;
		}
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&ab[i][0],&ab[i][1]);
     ^