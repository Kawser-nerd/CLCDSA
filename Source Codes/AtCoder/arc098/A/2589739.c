#include <stdio.h>
#include <stdlib.h>

char S[300001];
int E[300000];
int W[300000];

int main(void) {
  int N, i, min;
  scanf("%d", &N);
  scanf("%s", S);
  if (S[0] == 'W')
    W[0] = 1;
  for (i = 1; i < N; i++) {
    W[i] = W[i - 1];
    if (S[i] == 'W')
      W[i]++;
  }
  if (S[N - 1] == 'E')
    E[N - 1] = 1;
  for (i = N - 2; i >= 0; i--) {
    E[i] = E[i + 1];
    if (S[i] == 'E')
      E[i]++;
  }
  min = E[1];
  for (i = 1; i < N - 1; i++) {
    if (W[i - 1] + E[i + 1] < min)
      min = W[i - 1] + E[i + 1];
  }
  if (W[N - 2] < min)
    min = W[N - 2];
  printf("%d\n", min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^