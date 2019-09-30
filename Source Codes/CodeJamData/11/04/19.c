#include <stdio.h>
#include <stdlib.h>

#define NN 1000

int main()
{
  int T, N, C[NN];
  int w[NN];
  int i, j, k;
  int s, p;

  scanf("%d", &T);

  for (i = 0; i < T; i++) {
    scanf("%d", &N);
    for (j = 0; j < N; j++) {
      scanf("%d", &C[j]);
      w[j] = 0;
    }
    s = 0;
    for (j = 0; j < N; j++) {
      if (w[j]) continue;
      p = j+1;
      while (C[p-1] != p) {
	s++;
	p = C[p-1];
	w[p-1] = 1;
	if (p == j+1) break;
      }
    }

    printf("Case #%d: ", i+1);
    printf("%f\n", (float) s);
  }

  return 0;
}
