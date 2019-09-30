#include <stdio.h>
int prev(int idx, int P){
  int pos = (1<<P)*2-2-idx;
  pos = pos * 2 + 1;
  pos = (1<<P)*2-3-pos;
  return pos;
}
int main(){
  int M[1024];
  int tickets[1024];
  int cost[2048][11];
  int T, P;
  int i, j, k, c;
  scanf("%d",&T);
  for(c = 0; c<T; c++){
    scanf("%d",&P);
    for(i = 0; i<(1<<P); i++){
      scanf("%d",&M[i]);
    }
    for(i = 0; i<(1<<P)-1; i++){
      scanf("%d",&tickets[i]);
    }
    for(i = 0; i<(1<<P)*2-1; i++){
      for(j = 0 ; j<=P; j++){
        if(i<(1<<P) && j<=M[i])
          cost[i][j] = 0;
        else
          cost[i][j] = 1000000000;
      }
    }
    for(i = (1<<P); i<(1<<P)*2-1; i++){
      for(j = 0; j<=P; j++){
        //can buy this game
        int left = prev(i,P);
        int right = left+1;
        int a = tickets[i-(1<<P)] + cost[left][j] + cost[right][j];
        if(a < cost[i][j]){
          cost[i][j] = a;
        }
        //or not
        if(j<P){
          int a = cost[left][j+1] + cost[right][j+1];
          if(a < cost[i][j]){
            cost[i][j] = a;
          }
        }
        //printf("%d %d %d %d %d %d %d %d\n",i,j,cost[i][j],cost[left][j],cost[right][j],left,tickets[i-(1<<P)],a);
      }
    }
    int ret = 1000000000;
    for(j = 0; j<=P; j++){
      if(cost[(1<<P)*2-2][j] < ret){
        ret = cost[(1<<P)*2-2][j];
      }
    }
    printf("Case #%d: %d\n",c+1,ret);
  }
}
