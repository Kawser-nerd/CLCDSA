#include <stdio.h>

int N;
char S[300][301];

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%s", S[i]);
    // printf("%s\n", S[i]);
  }

  int ans = 0;
  for (int k = 0; k < N; ++k) {
    int ok = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ok &= S[(i+k)%N][j] == S[(j+k)%N][i];
      }
      if (!ok)
        break;
    }
    if (ok)
      ++ans;
  }
  ans *= N;
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S[i]);
     ^