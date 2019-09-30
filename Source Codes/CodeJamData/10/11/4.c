#include <stdio.h>
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};
int main(){
  char buf[100][100];
  int T, N, K;
  int i, j, k, c, d;
  int r, b;
  scanf("%d",&T);
  for(c = 0; c<T; c++){
    scanf("%d%d",&N,&K);
    gets(buf[0]);
    for(i = 0; i<N; i++){
      gets(buf[i]);
    }
    r = b = 0;
    for(i = 0; i<N; i++){
      k = 0;
      for(j = N-1; j>=0; j--){
        if(buf[i][j] == '.'){
          k++;
        } else {
          buf[i][j+k] = buf[i][j];
          if(k)buf[i][j] = '.';
        }
      }
    }
    for(i = 0; i<N; i++){
      for(j = 0 ;j<N; j++){
        if(buf[i][j] != '.'){
          for(d = 0; d<8; d++){
            int ok = 1;
            for(k = 1; k<K; k++){
              int ii = i + dx[d] * k;
              int jj = j + dy[d] * k;
              if(ii < 0 || ii>=N || jj<0 || jj>=N || buf[ii][jj] != buf[i][j]){
                ok = 0;
              }
            }
            if(ok){
              if(buf[i][j] == 'R')r = 1;
              else if(buf[i][j] == 'B')b = 1;
            }
          }
        }
      }
    }
    if(r && b){
      printf("Case #%d: Both\n",c+1);
    } else if(r){
      printf("Case #%d: Red\n",c+1);
    } else if(b){
      printf("Case #%d: Blue\n",c+1);
    } else {
      printf("Case #%d: Neither\n",c+1);
    }
  }

}
