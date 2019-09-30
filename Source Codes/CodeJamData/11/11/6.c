#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int T,tc,N,PD,PG,i,r;
  scanf("%d",&T);
  for(tc=1;tc<=T;++tc) {
    scanf("%d %d %d",&N,&PD,&PG);
    if((PG==0)||(PG==100)) {
      r=(PD==PG);
    } else {
      if(N>100) N=100;
      r=0;
      for(i=1;i<=N;++i) {
        if((PD*i)%100==0) {
          r=1;
          break;
        }
      }
    }
    if(r) {
      printf("Case #%d: Possible\n", tc);
    } else {
      printf("Case #%d: Broken\n", tc);
    }
  }
  return 0;
}

