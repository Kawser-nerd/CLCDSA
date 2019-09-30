#include <stdio.h>

int main(void) {
  int A, B, C, D, E, F;
  int A100, B100;
  int a, b, c, d;
  double ratio;
  double max_ratio = -1, current_ratio;
  int max_sugar, max_water;

  scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
  A100 = A * 100;
  B100 = B * 100;
  ratio = (double)E / (100.0 + E);

  for (a = 0; A100*a <= F; a++) {
    for (b = 0; A100*a + B100*b <= F; b++) {
      if (a == 0 && b == 0) continue;
      for (c = 0; A100*a + B100*b + C*c <= F; c++) {
        for (d = 0; A100*a + B100*b + C*c + D*d <= F; d++) {
          if (ratio >= (current_ratio = ((double)(C*c + D*d) / (A100*a + B100*b + C*c + D*d))) &&
            max_ratio < current_ratio) {
            max_sugar = C*c + D*d;
            max_water = A100*a + B100*b;
            max_ratio = (double)max_sugar / (max_water + max_sugar);
          }
        }
      }
    }
  }
  printf("%d %d\n", max_sugar + max_water, max_sugar);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
   ^