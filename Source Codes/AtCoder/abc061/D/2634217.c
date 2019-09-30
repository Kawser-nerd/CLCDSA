#include<stdio.h>

int main(){
  int n,m,a,b,i,j,k,flag=0;
  long c,g[1001][1001][2]={};
  scanf("%d %d",&n,&m);
  for(i=1;i<=n;i++)
    g[i][i][1]=1;
  for(i=0;i<m;i++){
    scanf("%d %d %ld",&a,&b,&c);
    g[a][b][0]=c;
    g[a][b][1]=1;
  }
  for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(g[i][k][1]&&g[k][j][1]&&(g[i][j][0]<g[i][k][0]+g[k][j][0]||g[i][j][1]==0)){
          g[i][j][1]=1;
          g[i][j][0]=g[i][k][0]+g[k][j][0];
        }
  for(i=1;i<=n;i++)
    if(g[i][i][0]>0&&g[i][n][1]==1)
      flag=1;
  /*for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
      printf("%ld ",g[i][j][0]);
    printf("\n");
  }*/
  if(flag)
    printf("inf\n");
  else
    printf("%ld\n",g[1][n][0]);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %ld",&a,&b,&c);
     ^