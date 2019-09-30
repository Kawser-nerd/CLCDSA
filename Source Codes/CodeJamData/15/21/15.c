#include <stdio.h>
#include <limits.h>

int main(void)
{
  int T;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases) {
    int N;
    scanf("%d", &N);
    int array[1000001];
    for (int i=0; i<=N; ++i)
      array[i] = INT_MAX;
    array[1] = 1;
    for (int i=1; i<N; ++i) {
      if (array[i+1] > array[i] + 1)
        array[i+1] = array[i] + 1;
      int reverse = 0;
      for (int this = i; this; this /= 10) {
        reverse *= 10;
        reverse += this % 10;
      }
      if (array[reverse] > array[i] + 1)
        array[reverse] = array[i] + 1;
    }
    printf("Case #%d: %d\n", cases, array[N]);
  }
  return 0;
}
