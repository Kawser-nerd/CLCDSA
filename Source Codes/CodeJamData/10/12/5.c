#include <stdio.h>
int abs(int n){
  return n<0?-n:n;
}
int main(){
  int T, D, I, M, N;
  int i, j, k,l, c, ret;
  int cost[200][256];
  int ins[256][256];
  int a[200];
  scanf("%d",&T);
  for(c = 0; c<T; c++){
    ret = 1000000;
    scanf("%d%d%d%d",&D,&I,&M,&N);
    for(i = 0; i<256; i++){
      cost[0][i] = 0;
    }
    for(i = 0; i<N; i++){
      scanf("%d",&a[i]);
      for(j = 0 ;j<256; j++){
        cost[i+1][j] = cost[i][j] + D; // delete this guy
      }
      for(j = 0; j<256; j++){//prev
        for(k = 0 ;k<256; k++){//end here now
          if(abs(j-k)<=M){//legal
            int cs = cost[i][j];
            cs += abs(a[i]-k);
            if(cs < cost[i+1][k])
              cost[i+1][k] = cs;
          }
        }
      }
      if(M) for(j = 0; j<256; j++){
        for(k = 0; k<256; k++){//insert crap afterwards
          int cs = cost[i+1][j];
          cs += (abs(j-k)+M-1)/M*I;
          if(cs < cost[i+1][k]){
            cost[i+1][k] = cs;
          }
        }
      }
    }
    for(i = 0; i<256; i++){
      if(cost[N][i] < ret){
        ret = cost[N][i];
      }
    }
    printf("Case #%d: %d\n",c+1,ret);
  }
}
