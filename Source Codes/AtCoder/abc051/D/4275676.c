#include <stdio.h>
#define INF 1 << 29

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int a[M],b[M],c[M],dist[N][N];

  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      if(i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  }

  for(int i = 0;i < M;i++){
    scanf("%d%d%d",&a[i],&b[i],&c[i]);
    a[i]--; b[i]--;
    dist[a[i]][b[i]] = dist[b[i]][a[i]] = c[i];
  }

  for(int k = 0;k < N;k++){
    for(int i = 0;i < N;i++){
      for(int j = 0;j < N;j++){
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }

  int ans = 0;
  for(int i = 0;i < M;i++){
    if(dist[a[i]][b[i]] < c[i]) ans++;
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a[i],&b[i],&c[i]);
     ^