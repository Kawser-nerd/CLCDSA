#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *p1, const void *p2) {
    return *(int *)p1 - *(int *)p2;
}

int main(int argc, char **argv) {
  int T, tc, N, X, R, L, i, k; double d;
  int s[200], u[200];
  scanf("%d", &T);
  for(tc=1; tc<=T; ++tc) {
      scanf("%d", &N);
      X = 0;
      for(i=0; i<N; ++i) {
          scanf("%d", &(s[i]));
          X += u[i] = s[i];
      }
      qsort(s, N, sizeof(int), cmp);
      R = X;
      for(i=0; i+1<N && R >= (i+1) * (s[i+1]-s[i]); ++i) {
          R -= (i+1) * (s[i+1]-s[i]);
      }
      L = s[i];
      k = i;
      printf("Case #%d:", tc);
      for(i=0; i<N; ++i) {
          d = 100 * ((double)L + (double)R / (k+1) - u[i]) / X;
          if(d < 0) d = 0;
          printf(" %lf", d);
      }
      printf("\n");
  }
  return 0;
}

