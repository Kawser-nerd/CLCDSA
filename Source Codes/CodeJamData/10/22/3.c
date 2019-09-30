#include <stdio.h>

int N, K, B, T;
int X[100];
int V[100];

int main()
{
  int t, tests, result;
  int i, j, k;

  scanf("%d", &tests);
  for (t = 1; t <= tests; ++t) {
    scanf("%d %d %d %d", &N, &K, &B, &T);
    for (i = 0; i < N; ++i) {
      scanf("%d", &X[i]);
    }
    for (i = 0; i < N; ++i) {
      scanf("%d", &V[i]);
    }
    result = 0;
    int ok = 0;
    j = K;
    k = 0;
    for (i = N - 1; i >= 0; --i) {
      if (k >= K) {
	ok = 1;
	break;
      }
      if (X[i] + V[i] * T < B) {
	result += j;
      } else {
	j--;
	k++;
	if (k >= K) {
	  ok = 1;
	  break;
	}
      }
    }
    if (!ok) {
      printf("Case #%d: IMPOSSIBLE\n", t);
    } else {
      printf("Case #%d: %d\n", t, result);
    }
  }
  
  return 0;
}
