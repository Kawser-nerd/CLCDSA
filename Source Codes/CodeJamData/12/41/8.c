#include <stdio.h>

#define LL long long int
#define MN 10050

LL x[MN];
LL len[MN];
LL elan[MN];

int main(void) {
  int T, N, i, cas, possible, j, p[MN];
  LL D, newelan;
  scanf("%d", &T);
  for(cas=1; cas<=T; cas++) {
    scanf("%d", &N);
    for(i=0; i<N; i++) {
      scanf("%lld", x+i);
      scanf("%lld", len+i);
    }
    scanf("%lld", &D);
    
    for(i=0; i<N; i++) {
      elan[i]=0;
      p[i]=0;
    }
    
    elan[0]=x[0];
    p[0]=1;
    for(i=1; i<N; i++) {
      for(j=0; j<i; j++) {
        newelan = elan[i];
        if(p[j] && elan[j]+x[j] >= x[i]) {
          p[i] = 1;
          if(len[i] >= x[i] - x[j]) {
            newelan = x[i] - x[j];
          } else {
            newelan = len[i];
          }
        }
        if(newelan > elan[i]) {
          elan[i] = newelan;
        }
      }
    }
    
    possible = 0;
    for(i=0; i<N; i++) {
      if ((x[i]+elan[i]) >= D)
        possible = 1;
    }
    
    fprintf(stderr, "elan[%d]=%lld at %lld vs %lld (%d)\n", N-1, elan[N-1], x[N-1], D, possible);
    
    printf("Case #%d: ", cas);
    if(possible) {
      printf("YES");
    } else {
      printf("NO");
    }
    printf("\n");
  }
  return 0;
}
