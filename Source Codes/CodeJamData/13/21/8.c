#include <stdio.h>

#define NMAX 102
int motes[NMAX];

int min(int a, int b) {
  return a>b?b:a;
}

int cmp(const void *a, const void *b) {
  return (*((int*) a) - *((int*) b));
}

int main() {
  int T;
  scanf("%d", &T);
  int ncase;
  for (ncase=0; ncase<T; ncase++) {
    printf("Case #%d: ", ncase+1);
    int A, N;
    scanf("%d", &A);
    scanf("%d", &N);
    int i;
    for (i=0; i<N; i++) {
      int v;
      scanf("%d", &v);
      motes[i] = v;
    }
    int pos = 0;
    qsort(motes, N, sizeof(int), &cmp);
    //for (i=0; i<N; i++) {
    //  printf(">mote %d\n", motes[i]);
    //}
    int best = N;
    int added = 0;
    if (A == 1) {
      // won't be able to add
      printf("%d\n", N);
      continue;
    }
    while (pos < N) {
      if (motes[pos] < A) {
        //printf(">we eat mote %d of size %d\n", pos, motes[pos]);
        A += motes[pos];
        pos++;
      } else {
        //printf(">we can't eat mote %d of size %d\n", pos, motes[pos]);
        //printf(">current proposition added %d and left %d\n", added, N-pos);
        best = min(best, added + N - pos);
        int pA = A;
        A += A-1;
        added++;
        //printf(">now we added %d and went from %d to %d to reach %d\n", motes[pos]);
      }
    }
    //printf(">only by adding we need to add %d\n", added);
    best = min(best, added);
    printf("%d\n", best);
  }
  return 0;
}
