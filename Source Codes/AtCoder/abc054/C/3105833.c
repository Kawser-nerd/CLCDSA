#include<stdio.h>
int g[9][9]={};
int visit[9]={},n;
int dfs(int p){
  visit[p]=1;
  int flag=1,cnt=0;
  for(int i=1;i<=n;i++)
    flag*=visit[i];
  if(flag){
    visit[p]=0;
    return 1;
  }
  for(int i=2;i<=n;i++)
    if(g[p][i]==1&&visit[i]==0)
      cnt+=dfs(i);
  visit[p]=0;
  return cnt;
}

int main(){
  int m,a,b;
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    g[a][b]=g[b][a]=1;
  }
  printf("%d\n",dfs(1));
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^