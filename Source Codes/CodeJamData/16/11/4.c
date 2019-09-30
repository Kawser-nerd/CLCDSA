#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001

int main(int argc, char **argv) {
  int T, tc, n;
  char S[MAXN+1];
  char W[2*MAXN+1];
  char *I, *L, *M;

  scanf("%d", &T);
  for(tc=1; tc<=T; ++tc) {
      scanf("%s", S);
      L = M = W + MAXN;
      for(I=S, n=1; *I; ++I, ++n) {
          *(L-1) = *M = *I;
          if(strncmp(L-1, L, n) > 0) --L; else ++M;
      }
      *M = 0;
      printf("Case #%d: %s\n", tc, L);
  }
  return 0;
}

