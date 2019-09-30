#include <stdio.h>
int main(void)
{
  int n,m;
  int r[11][11]={0};
  int i,j,k;
  scanf("%d%d",&n,&m);
  for(i=0;i<=n;++i){
    for(j=0;j<=n;++j){
      r[i][j]=100;
    }
    r[i][i]=0;
  }
  for(i=0;i<m;++i){
    int a,b;
    scanf("%d%d",&a,&b);
    r[a][b]=r[b][a]=1;
  }
  for(i=0;i<=n;++i){
    for(j=0;j<=n;++j){
      for(k=0;k<=n;++k){
        if(r[j][k] > r[j][i] + r[i][k]){
          r[j][k]=r[j][i] + r[i][k];
        }
      }
    }
  }
  for(i=1;i<=n;++i){
    int c=0;
    for(j=1;j<=n;++j){
      if(r[i][j]==2){
        ++c;
      }
    }
    printf("%d\n",c);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^