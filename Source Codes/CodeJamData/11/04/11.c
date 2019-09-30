
#include <stdio.h>
#include <stdlib.h>


int intcmp(const void *p1, const void *p2) {
  return *(int*)p1 - *(int*)p2;
}

int main() {
  int T = 0;
  int C[2000];
  int S[2000];
  int used[2000];
  int pos[2000];
  double P[2000];
  int N;
  int i;
  int sum;
  int min, minwhich;
  int cz, j;
  double p;
  int unused;


  scanf("%d", &T);
  for(cz=1;cz<=T;cz++) {
    scanf("%d", &N);
    for(i=0;i<N;i++) scanf("%d", &C[i]);
    memcpy(S, C, i*sizeof(int));

    qsort(S, N, sizeof(int), intcmp);

    memset(used, 0, sizeof(used));

    p = 0;

    while(1) {
      unused = 0;
      for(i=0;i<N;i++) {
        if(C[i] == S[i]) used[i] = 1;
        else unused++;
      }
      if(!unused) break;

      p = 0;

      for(i=0;i<N;i++) {
        if(!used[i]) {
          pos[i] = 0;
          for(j=0;j<N;j++) {
            if(!used[j] && C[i] == S[j]) pos[i]++;
          }
//          printf("[%d] = %d/%d\n", i, pos[i], unused);
          p += 1.0*unused/pos[i];
        }
      }

      p /= unused;
      break;

    }


    printf("Case #%d: %.6f\n", cz, p);
  }

  return 0;
}
