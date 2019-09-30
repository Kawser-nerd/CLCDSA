#include<stdio.h>

int main(){
  int n,i,j,k,m,g[100][100]={},gg[100][100]={},a,b,c,cnt=0;
  scanf("%d %d\n",&n,&m);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i!=j)
        g[i][j]=gg[i][j]=1001;
    }
  }
  for(i=0;i<m;i++){
    scanf("%d %d %d",&a,&b,&c);
    g[a-1][b-1]=g[b-1][a-1]=gg[a-1][b-1]=gg[b-1][a-1]=c;
  }
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(g[i][j]>g[i][k]+g[k][j])
          g[i][j]=g[i][k]+g[k][j];
      }
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(gg[i][j]!=1001&&gg[i][j]!=g[i][j])
        cnt++;
    }
  }
  printf("%d\n",cnt/2);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d\n",&n,&m);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a,&b,&c);
     ^