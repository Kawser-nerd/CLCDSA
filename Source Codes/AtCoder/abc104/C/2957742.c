#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
  int D, G;
  int p[10], c[10];
  scanf("%d %d", &D, &G);
  G /= 100;
  for (int i = 0; i < D; i++) {
    scanf("%d %d", &p[i], &c[i]);
    c[i] /= 100;
  }

  int all = 0, ans[10] = {}, min = 0x7FFFFFFF;
  while (all < (1 << D)) {
    int score = 0;
    for (int i = 0; i < D; i++) {
      ans[i] = ((all & (1 << i)) > 0) * p[i];
      score += ans[i]*(i+1) + (ans[i]>0)*c[i];
    }
    for (int i = D-1; G > score && i >= 0; i--) {
      if ((all & (1 << i)) > 0) continue;
      if (ceil((G - score) / (double)(i+1)) >= p[i]) {
        ans[i] = p[i];
        score += (i+1)*p[i] + c[i];
      } else {
        ans[i] = ceil(((double)G - score) / (i+1));
        score += (i+1)*ans[i];
      }
    }
    int n = 0;
    for (int i = 0; i < D; i++) n += ans[i];
    if (min >= n) {
      min = n;
    }
    all++;
  }
  printf("%d\n", min);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &D, &G);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &p[i], &c[i]);
     ^